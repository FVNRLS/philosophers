/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 16:05:23 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	take_forks(t_phil *phil, t_id *id)
{
	pthread_mutex_lock(&phil->forks[id->fork_left]);
	pthread_mutex_lock(&phil->forks[id->fork_right]);
	if (phil->died == false)
	{
		pthread_mutex_lock(&phil->std_out);
		printf("%ld %d has taken a fork\n", phil->tstamp->t_current, id->phil);
		pthread_mutex_unlock(&phil->std_out);
	}
}

void	eat(t_phil *phil, t_id *id)
{
	if (phil->died == false)
	{
		pthread_mutex_lock(&phil->std_out);
		printf("%ld %d is eating\n", phil->tstamp->t_current, id->phil);
		pthread_mutex_unlock(&phil->std_out);
	}
	ft_usleep(phil->t_eat);
	get_current_time(phil);
	phil->tstamp->t_last_eat = phil->tstamp->t_current;
	pthread_mutex_unlock(&phil->forks[id->fork_right]);
	pthread_mutex_unlock(&phil->forks[id->fork_right]);
}

void	ph_sleep(t_phil *phil, t_id *id)
{
	if (phil->died == false)
	{
		pthread_mutex_lock(&phil->std_out);
		printf("%ld %d is sleeping\n", phil->tstamp->t_current, id->phil);
		pthread_mutex_unlock(&phil->std_out);
	}
	ft_usleep(phil->t_sleep);
}

void	think(t_phil *phil, t_id *id)
{
	check_phil_died(phil);
	if (phil->died == false)
	{
		pthread_mutex_lock(&phil->std_out);
		printf("%ld %d is thinking\n", phil->tstamp->t_current, id->phil);
		pthread_mutex_unlock(&phil->std_out);
	}
}