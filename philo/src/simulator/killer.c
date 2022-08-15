/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 12:42:55 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	print_input_data(t_phil *phil)
{
	printf("\nnum phil: 		%d\n", phil->n_phil);
	printf("time to die: 		%ld\n", phil->t_die);
	printf("time to eat: 		%ld\n", phil->t_eat);
	printf("time to sleep: 		%ld\n", phil->t_sleep);
	printf("num times to eat: 	%ld\n", phil->n_eat);
}

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

//	//TODO: del!
//	printf("t_cur:		%ld\n", phil->tstamp->t_current);
//	printf("t_last_eat:	%ld\n", phil->tstamp->t_last_eat);
//	printf("t_diff:		%ld\n", phil->tstamp->t_diff);
}

bool	check_phil_died(t_phil *phil)
{
	get_time_diff(phil);
	if (phil->tstamp->t_diff >= phil->t_die && phil->died == false)
	{
		if (phil->die_msg_displayed == false)
		{
			phil->die_msg_displayed = true;
			printf("%ld %d died\n", phil->tstamp->t_current, phil->index);
		}
		phil->died = true;
//		pthread_mutex_unlock(&phil->fork);
		return (true);
	}
	else if (phil->died == true)
	{
//		pthread_mutex_unlock(&phil->fork);
		return (true);
	}
	else
		return (false);
}
