/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/18 19:16:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	take_forks(t_phil *phil)
{
	if (phil->data->died == false)
	{
		pthread_mutex_lock(&phil->data->forks[phil->fork_left]);
		print_status(phil, LEFT_FORK_TAKEN);
	}
	if (phil->data->died == false)
	{
		pthread_mutex_lock(&phil->data->forks[phil->fork_right]);
		print_status(phil, RIGHT_FORK_TAKEN);
	}
}

void	eat(t_phil *phil)
{
	get_current_time(phil);
	phil->t_last_eat = phil->t_current;
	if (phil->data->died == false)
	{
		phil->status = BUSY;
		print_status(phil, IS_EATING);
		ft_usleep(phil->data->t_eat);
		pthread_mutex_unlock(&phil->data->forks[phil->fork_right]);
		pthread_mutex_unlock(&phil->data->forks[phil->fork_left]);
	}
}

void	ph_sleep(t_phil *phil)
{
	if (phil->data->died == false)
	{
		phil->status = BUSY;
		print_status(phil, IS_SLEEPING);
		ft_usleep(phil->data->t_sleep);
	}
}

void	think(t_phil *phil)
{
	phil->status = FREE;
	get_time_diff(phil);
	if (phil->data->died == false)
		print_status(phil, IS_THINKING);
}

