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
	gettimeofday(&phil->time, NULL);
	phil->tstamp->t_current =
			((phil->time.tv_sec * 1000) + (phil->time.tv_usec / 1000));
}

static void	get_time_diff(t_phil *phil)
{
	get_current_time(phil);
	phil->tstamp->t_diff = phil->tstamp->t_current - phil->tstamp->t_last_eat;
}

bool	check_phil_died(t_phil *phil, t_id *id)
{
	get_time_diff(phil);
	if (phil->tstamp->t_diff >= phil->t_die && phil->died == false)
	{
		if (phil->die_msg_displayed == false)
		{
			print_status(phil, id, PHIL_DIED);
			phil->die_msg_displayed = true;
		}
		phil->died = true;
		return (true);
	}
	else if (phil->died == true)
		return (true);
	else
		return (false);
}
