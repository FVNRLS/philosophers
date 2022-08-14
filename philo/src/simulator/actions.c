/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/14 16:53:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	take_fork(t_phil *phil, int index)
{
	pthread_mutex_lock(&phil->fork);
	check_kill_phil(phil);
	if (phil->tstamp->res_ms < phil->t_die && phil->phil_died == false)
		printf("%ld ms philosopher %d has taken a fork\n", phil->tstamp->res_ms, index);
}

void	eat(t_phil *phil, int index)
{
	int i;

	if (phil->tstamp->res_ms < phil->t_die && phil->phil_died == false)
		printf("%ld ms philosopher %d is eating\n", phil->tstamp->res_ms, index);
	i = 0;
	while (i < phil->t_eat)
	{
		check_kill_phil(phil);
		usleep(1000);
		i++;
	}
	pthread_mutex_unlock(&phil->fork);
}

void	ph_sleep(t_phil *phil, int index)
{
	int i;

	if (phil->tstamp->res_ms < phil->t_die && phil->phil_died == false)
		printf("%ld ms philosopher %d is sleeping\n", phil->tstamp->res_ms, index);
	i = 0;
	while (i < phil->t_sleep)
	{
		check_kill_phil(phil);
		usleep(1000);
		i++;
	}
}

void	think(t_phil *phil, int index)
{
	check_kill_phil(phil);
	printf("%ld ms philosopher %d is thinking\n", phil->tstamp->res_ms, index);
}