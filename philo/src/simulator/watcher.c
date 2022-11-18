/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 19:53:45 by rmazurit         ###   ########.fr       */
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
		ft_usleep(phil, phil->data->t_die);
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

/* Checks if a particular philosopher exceeded the t_die limit */
static bool	check_death(t_phil *phil, int i)
{
	get_time_diff(&phil[i]);
	if (phil[i].t_diff >= phil->data->t_die)
	{
		phil->data->died = true;
		put_all_forks(phil->data);
		print_status(&phil[i], PHIL_DIED);
		return (true);
	}
	return (false);
}

/*
 * Runs continuously in the background in main thread.
 * Checks if the philosopher has died or is sated.
 * If yes - the appropriate flag is set to true and the simulation is stopped.
 * */
void	watch_phils(t_phil *phil)
{
	int		i;
	bool	died;

	died = false;
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
				phil[i].sated = false;
			}
			if (phil->data->n_sated == phil->data->n_phil)
				return ;
			if (phil[i].status == FREE)
				died = check_death(phil, i);
			if (died == true)
				return ;
			i++;
		}
	}
}
