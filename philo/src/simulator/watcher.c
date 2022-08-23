/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 16:52:11 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
 * Hardcoded solution if the user enters the number 1 as the first argument
 * (number of philosophers).
 * The philosopher must take only one fork, but must not start eating and
 * dies instantly.
 * */
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

/*
 * Check if all philosopher have eaten min_meals.
 * If yes - set 'sated' flag to true, which causes stop of the simulation.
 * */
void	check_if_sated(t_phil *phil)
{
	if (phil->meals == phil->data->min_meals)
	{
		phil->sated = true;
		return ;
	}
}

/*
 * Runs continuously in the background in main thread.
 * Checks if the philosopher has died or is sated.
 * If yes - the appropriate flag is set to true and the simulation is stopped.
 * */

void	watch_phils(t_phil *phil)
{
	int	i;

	if (check_if_lonely(phil) == true)
		return ;
	while (phil->data->died == false)
	{
		i = 0;
		while (i < phil->data->n_phil)
		{
			if (phil[i].sated == true)
			{
				phil->data->n_sated++;
				if (phil->data->n_sated == phil->data->n_phil)
					return ;
			}
			if (phil[i].status == FREE)
			{
				get_time_diff(&phil[i]);
				if (phil[i].t_diff >= phil->data->t_die)
				{
					phil->data->died = true;
					put_all_forks(phil->data);
					print_status(&phil[i], PHIL_DIED);
					return ;
				}
			}
			i++;
		}
	}
}
