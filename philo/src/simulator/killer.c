/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 17:39:11 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	get_current_time(t_phil *phil)
{
	gettimeofday(&phil->data->time, NULL);
	phil->data->t_current =
			((phil->data->time.tv_sec * 1000) + (phil->data->time.tv_usec / 1000));
}

static void	get_time_diff(t_phil *phil)
{
	get_current_time(phil);
	phil->data->t_diff = phil->data->t_current - phil->data->t_last_eat;
}

bool	check_phil_died(t_phil *phil)
{
	get_time_diff(phil);
	if (phil->data->t_diff >= phil->data->t_die && phil->data->died == false)
	{
			print_status(phil, PHIL_DIED);
		phil->data->died = true;
		return (true);
	}
	else if (phil->data->died == true)
		return (true);
	else
		return (false);
}
