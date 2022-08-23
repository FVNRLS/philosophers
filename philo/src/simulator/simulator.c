/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 14:53:02 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
 * Main routine function that every philosopher (thread) executes as long
 * he is not dead or sated.
 * In main thread the watcher thread is created, which in parallel
 * monitors the status of the philosopher and checks whether he died or not.
 * To prevent a deadlock, all even philosophers start to eat with
 * (phil->data->t_eat / 2) delay -> synchronized threading.
 * The routine looks like this and rotates in a while-loop:
	take forks -> eat -> sleep -> think -> take forks -> eat -> sleep ....
 * After every meal the min time of meals is checked, so if the philosopher is
 * sated, he exits with code PHIL_SATED.
 * If the philosopher dies or is sated, while loop stops by appropriate flags.
 * */
static void	*simulate(void *arg)
{
	t_phil	*phil;

	phil = arg;
	if (phil->id % 2 == 0)
		ft_usleep(phil, (phil->data->t_eat / 2));
	while (phil->data->died == false)
	{
		take_forks(phil);
		eat(phil);
		phil->meals++;
		check_if_sated(phil);
		if (phil->sated == true)
		{
			phil->data->n_sated++;
			break;
		}
		ph_sleep(phil);
		think(phil);
	}
	return (NULL);
}

/*
 * Joins all threads to the main thread after the execution.
 * The function returns false if join fails, which causes exit
 * fom the program with EXIT_FAILURE code.
 * */
static bool join_threads(t_phil *phil, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_phil)
	{
		if (pthread_join(phil->thread[i], NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

/*
 * Pass the array of structures inside the pthread_create function and create
 * threads, which are the philosophers.
 * By creating every thread starts the routine simulation process.
 * The function returns false if threads couldn't be created, which causes exit
 * fom the program with EXIT_FAILURE code.
 * */
static bool	start_threads(t_phil *phil, t_data *data)
{
	int i;

	phil->thread = NULL;
	phil->thread = malloc((sizeof(pthread_t) * data->n_phil));
	if (!phil->thread)
		return (false);
	i = 0;
	while (i < data->n_phil)
	{
		if (pthread_create(&phil->thread[i], NULL, &simulate,
						   (void *)&phil[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

/*
 * Initializes the start parameters for each philosopher (ID, forks, status..).
 * All philosophers refer to the same data phil->data.
 * For each phil. the forks left ad right are defined.
 * The start time is initialized, and is the same for all philosophers.
 * Status FREE is for watcher and means with true, that the philosopher can be
 * checked and killed by the watcher in the time.
 * */
static void	init_phils(t_phil *phil, t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_phil)
	{
		phil[i].data = data;
		phil[i].id = i + 1;
		phil[i].fork_left = phil[i].id - 1;
		if (phil[i].id == data->n_phil)
			phil[i].fork_right = 0;
		else
			phil[i].fork_right = phil[i].id;
		phil->t_last_eat = 0;
		phil->status = FREE;
		phil->meals = 0;
		phil->sated = false;
		i++;
	}
	phil->data->died = false;
	phil->data->n_sated = 0;
	gettimeofday(&phil->data->time, NULL);
	phil->data->t_start = ((phil->data->time.tv_sec * 1000)
			+ (phil->data->time.tv_usec / 1000));
}

/*
 * Allocate and try to run the threads:
 * If successful:
 	-> start the looped watcher to intercept the flags 'died' and 'sated'.
 * At the end free the allocated memory for the philosophers.
 * Join the threads to the main thread after the execution.
 * */
int	run_simulation(t_data *data)
{
	t_phil 		*phil;
	bool		threads_started;
	bool		threads_joined;

	phil = malloc(sizeof(t_phil) * data->n_phil);
	if (!phil)
		return (EXIT_FAILURE);
	init_phils(phil, data);
	threads_started = start_threads(phil, data);
	if (threads_started == false)
	{
		ft_free_phils(phil);
		return (EXIT_FAILURE);
	}
	watch_phils(phil);
	threads_joined = join_threads(phil, data);
	ft_free_phils(phil);
	if (threads_joined == false)
	{
		ft_free_phils(phil);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}