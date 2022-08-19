/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/19 16:16:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

static bool	check_if_lonely(t_phil *phil)
{
	if (phil->data->n_phil == 1)
	{
		print_status(phil, FORK_TAKEN);
		print_status(phil, PHIL_DIED);
		pthread_mutex_unlock(&phil->data->forks[phil->fork_left]);
		phil->data->died = true;
		return (true);
	}
	return (false);
}

static void	check_min_meals(t_phil *phil)
{
	int i;
	int min;

	if (phil->data->min_meals == 0)
		return ;
	i = 0;
	min = phil[0].meals;
	while (i < phil->data->n_phil)
	{
		if (phil[i].meals < min)
			min = phil[i].meals;
		i++;
	}
	if (min >= phil->data->min_meals)
		phil->data->all_sated = true;
}

void	get_current_time(t_phil *phil)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	phil->t_current =
			((current.tv_sec * 1000) + (current.tv_usec / 1000)) - phil->data->t_start;
}

void	get_time_diff(t_phil *phil)
{
	get_current_time(phil);
	phil->t_diff = phil->t_current - phil->t_last_eat;
}

void	watch_phils(t_phil *phil)
{
	int 	i;
	bool 	lonely;

	lonely = check_if_lonely(phil);
	if (lonely == true)
		return ;
	i = 0;
	while (i < phil->data->n_phil)
	{
		check_min_meals(phil);
		if (phil->data->all_sated == true)
			return ;
		if (phil[i].status == FREE)
		{
			get_time_diff(&phil[i]);
			if (phil[i].t_diff >= phil->data->t_die)
			{
				phil->data->died = true;
				print_status(&phil[i], PHIL_DIED);
				printf("diff phil %d:	%ld		last eat:	%ld\n", phil[i].id, phil[i].t_diff, phil[i].t_last_eat);
				return ;
			}
		}
		i++;
		if (i == phil->data->n_phil)
			i = 0;
	}
}
