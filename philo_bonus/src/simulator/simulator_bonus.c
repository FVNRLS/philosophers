/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 16:39:44 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

static void detach_watcher(pthread_t watcher)
{
	int	ret;

	ret = pthread_detach(watcher);
	if (ret != 0)
		exit(EXIT_FAILURE);
}

/*
 * Main routine function that every philosopher (child process) executes as long
 * he is not dead or sated.
 * Before the actual routine, a watcher thread is created, which in parallel
 * monitors the status of the philosopher and checks whether he died or not.
 * The routine looks like this and rotates in a while-loop:
	take forks -> eat -> sleep -> think -> take forks -> eat -> sleep ....
 * After every meal the min time of meals is checked, so if the philosopher is
 * sated, he exits with code PHIL_SATED.
 * If the philosopher dies, the while loop stops and the watcher is detached
 * and the child process exits with code PHIL_DIED.
 * The codes were caught from the watcher in parent process, which decides to
 * terminate or to continue the program.
 * */
static void	simulate(t_phil *phil)
{
	pthread_t	watcher;

	if (phil->id % 2 == 0)
		ft_usleep(phil, (phil->data->t_eat / 2));
	if (pthread_create(&watcher, NULL, (void *)&check_death, (void *)phil) != 0)
		exit(EXIT_FAILURE);
	while (phil->died == false)
	{
		take_forks(phil);
		eat(phil);
		phil->meals++;
		check_if_sated(phil);
		if (phil->sated == true)
		{
			sem_post(phil->data->fork);
			sem_post(phil->data->fork);
			exit(PHIL_SATED);
		}
		ph_sleep(phil);
		think(phil);
	}
	detach_watcher(watcher);
	exit(PHIL_DIED);
}

/*
 * The start parameters will always be the same at the beginning for each child
 * process. All philosophers refer to the same start time (t_start).
 * Status FREE is for watcher and means with true, that the philosopher can be
 * checked and killed by the watcher in the time.
 * */
static void	init_start_params(t_phil *phil)
{
	struct timeval	current;

	phil->t_last_eat = 0;
	phil->meals = 0;
	gettimeofday(&current, NULL);
	phil->t_start = ((current.tv_sec * 1000) + (current.tv_usec / 1000));
	phil->sated = false;
	phil->status = FREE;
	phil->died = false;
}

/*
 *	Initialize the start parameters (always the same for all philosophers).
 *	Initialize the philosophers and start the routine function (simulate)
 *	for each child process.
 * */
static bool	run_procs(t_phil *phil)
{
	int i;

	init_start_params(phil);
	i = 0;
	while (i < phil->data->n_phil)
	{
		phil->id = i + 1;
		phil->proc[i] = fork();
		if (phil->proc[i] < 0)
		{
			kill(0, SIGKILL);
			print_error(FORK_ERROR);
			return (false);
		}
		else if (phil->proc[i] == 0)
			simulate(phil);
		i++;
	}
	return (true);
}

/*
 * Allocate and try to run the processes:
 * If successful:
 	-> start the watcher to intercept the exit codes for the child processes.
 * At the end free the allocated memory.
 * */
void	run_simulation(t_data *data)
{
	t_phil	phil;
	bool	procs_runned;

	phil.data = data;
	phil.proc = malloc(sizeof(pid_t) * phil.data->n_phil);
	if (!phil.proc)
		return ;
	procs_runned = run_procs(&phil);
	if (procs_runned == true)
		watch_phils(&phil);
	free(phil.proc);
	phil.proc = NULL;
}