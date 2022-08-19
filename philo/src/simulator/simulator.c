/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/19 12:45:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

static void	*simulate(void *arg)
{
	t_phil	*phil;

	phil = arg;
	if (phil->id % 2 == 0)
		ft_usleep(phil->data->t_eat / 2);
	while (phil->data->died == false && phil->data->all_sated == false)
	{
//		printf("sated: %d\n", phil->data->all_sated);
//		printf("min meals: %ld\n", phil->data->min_meals);
		take_forks(phil);
		eat(phil);
		ph_sleep(phil);
		think(phil);
	}
	return (NULL);
}

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

static bool	start_threads(t_phil *phil, t_data *data)
{
	int i;

	phil->thread = malloc((sizeof(pthread_t) * data->n_phil));
	i = 0;
	while (i < data->n_phil)
	{
		if (pthread_create(&phil->thread[i], NULL, &simulate, (void *)&phil[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

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
		i++;
	}
	phil->data->died = false;
	phil->data->all_sated = false;
	gettimeofday(&phil->data->time, NULL);
	phil->data->t_start = ((phil->data->time.tv_sec * 1000) + (phil->data->time.tv_usec / 1000));
}

int	start_simulation(t_data *data)
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
		free(phil->thread);
		phil->thread = NULL;
		return (EXIT_FAILURE);
	}
	watch_phils(phil);
	threads_joined = join_threads(phil, data);
	if (threads_joined == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}