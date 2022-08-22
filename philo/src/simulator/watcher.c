/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 19:25:52 by rmazurit         ###   ########.fr       */
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
 * Check if all philosopher have eaten once min_meals.
 * For this iterates through all philosophers and compares the number of meals.
 * If all are sated, set the sated flag to true.
 * It's not defined by the subject what a philosopher should do when sated,
 * so he continues to eat until ALL philosophers are sated.
 * */
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

/*
 * Runs continuously in the background in main thread.
 * Checks if the philosopher has died or is sated.
 * If yes - the appropriate flag is set to true and the simulation is stopped.
 * */
void	watch_phils(t_phil *phil)
{
	int 	i;

	if (check_if_lonely(phil) == true)
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
				return ;
			}
		}
		i++;
		if (i == phil->data->n_phil)
			i = 0;
	}
}
