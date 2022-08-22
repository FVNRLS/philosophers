/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_calculato_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:00:11 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 11:46:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

void	get_current_time(t_phil *phil)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		exit(EXIT_FAILURE);
	phil->t_current =
			((current.tv_sec * 1000) + (current.tv_usec / 1000)) - phil->t_start;
}

void	get_time_diff(t_phil *phil)
{
	get_current_time(phil);
	phil->t_diff = phil->t_current - phil->t_last_eat;
}