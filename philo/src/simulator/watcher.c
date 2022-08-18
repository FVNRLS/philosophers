/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/18 13:27:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	get_current_time(t_phil *phil)
{
	gettimeofday(&phil->data->time, NULL);
	phil->t_current =
			((phil->data->time.tv_sec * 1000) + (phil->data->time.tv_usec / 1000));
}

void	get_time_diff(t_phil *phil)
{
	get_current_time(phil);
	if (phil->t_last_eat == 0)
		phil->t_diff = 0;
	else
		phil->t_diff = phil->t_current - phil->t_last_eat;
}

//void	kill_phil(t_phil)
//{
//
//}

void	watch_phils(t_phil *phil)
{
	int 	i;
	i = 0;
	while (i < phil->data->n_phil)
	{
		if (phil[i].t_last_eat != 0)
			get_time_diff(&phil[i]);
		if (phil[i].t_diff >= phil->data->t_die)
		{
			printf("diff phil %d:	%ld		last eat:	%ld\n", phil[i].id, phil[i].t_diff, phil[i].t_last_eat);
			print_status(&phil[i], PHIL_DIED);
			phil->data->died = true;
			return ;
		}
		i++;
		if (i == phil->data->n_phil)
			i = 0;
	}
}
