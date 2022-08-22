/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:17:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 19:17:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
 * Calculate the current time, converted to milliseconds.
 * The current time always refers to the time, where the child processes are
 * being started (t_start), so the current timestamp always starts from 0ms.
 * */
void	get_current_time(t_phil *phil)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	phil->t_current =
			((current.tv_sec * 1000) + (current.tv_usec / 1000))
			- phil->data->t_start;
}

/*
 * Calculate the value t_diff as the difference between the current time and
 * the time when the philosopher started eating last time.
 * The value is used for comparison against t_die for the watcher to
 * decide if the philosopher died or not.
 * */
void	get_time_diff(t_phil *phil)
{
	get_current_time(phil);
	phil->t_diff = phil->t_current - phil->t_last_eat;
}