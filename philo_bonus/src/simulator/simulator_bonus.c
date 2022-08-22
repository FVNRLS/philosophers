/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/21 19:11:24 by rmazurit         ###   ########.fr       */
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
}

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

static void	run_procs(t_phil *phil)
{
	int i;

	i = 0;
	init_start_params(phil);
	while (i < phil->data->n_phil)
	{
		phil->id = i + 1;
		phil->proc = fork();
		if (phil->proc < 0)
		{
			kill(0, SIGINT);
			print_error(FORK_ERROR);
			destroy_semaphores(phil->data);
			exit(EXIT_FAILURE);
		}
		else if (phil->proc == 0)
			simulate(phil);
		i++;
	}
}

void	run_simulation(t_data *data)
{
	t_phil	phil;

	phil.data = data;
	run_procs(&phil);
	watch_phils(&phil);
}