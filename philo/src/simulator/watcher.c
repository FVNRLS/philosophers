/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/18 19:45:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

static bool	check_if_lonely(t_phil *phil)
{
	if (phil->data->n_phil == 1)
	{
		print_status(phil, PHIL_DIED);
		phil->data->died = true;
		return (true);
	}
	return (false);
}

void	get_current_time(t_phil *phil)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	phil->t_current =
			((current.tv_sec * 1000) + (current.tv_usec / 1000)) - phil->data->t_start;
}

void	get_time_diff(t_phil *phil)
{
	if (phil->t_last_eat == 0)
		phil->t_diff = 0;
	else
	{
		get_current_time(phil);
		phil->t_diff = phil->t_current - phil->t_last_eat;
	}
}

void	watch_phils(t_phil *phil)
{
	int 	i;
	bool 	lonely;

	lonely = check_if_lonely(phil);
	if (lonely == true)
		return ;
	i = 0;
	while (i < phil->data->n_phil)
	{
		if (phil[i].status == FREE)
			get_time_diff(&phil[i]);
		if (phil[i].t_diff >= phil->data->t_die)
		{
			phil->data->died = true;
			print_status(&phil[i], PHIL_DIED);
			printf("diff phil %d:	%ld		last eat:	%ld\n", phil[i].id, phil[i].t_diff, phil[i].t_last_eat);
			return ;
		}
		i++;
		if (i == phil->data->n_phil)
			i = 0;
	}
}
