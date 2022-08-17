/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/17 19:54:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	get_current_time(t_phil *phil)
{
	gettimeofday(&phil->data->time, NULL);
	phil->data->t_current =
			((phil->data->time.tv_sec * 1000) + (phil->data->time.tv_usec / 1000));
}

static void	get_time_diff(t_phil *phil, int index)
{
	get_current_time(phil);
	phil[index].t_diff = phil->data->t_current - phil->t_last_eat;
}

//void	kill_phil(t_phil)
//{
//
//}

void	watch_phils(t_phil *phil)
{
	int 	i;

	i = 0;
	ft_usleep(10000);
	while (phil->data->died == false)
	{
		while (i < phil->data->n_phil)
		{
			get_time_diff(phil, i);
			printf("t_diff phil %d: %ld\n", i + 1, phil[i].t_diff);
			if (phil[i].t_diff >= phil->data->t_die)
			{
				print_status(phil, PHIL_DIED);
				phil->data->died = true;
				return ;
			}
//						kill_phil()
			i++;
		}
		i = 0;
	}
}
