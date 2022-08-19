/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/19 16:10:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

void	take_forks(t_phil *phil)
{
	phil->status = FREE;
	if (phil->data->died == false && phil->data->all_sated == false)
	{
		pthread_mutex_lock(&phil->data->forks[phil->fork_left]);
		print_status(phil, FORK_TAKEN);
	}
	if (phil->data->died == false && phil->data->all_sated == false)
	{
		pthread_mutex_lock(&phil->data->forks[phil->fork_right]);
		print_status(phil, FORK_TAKEN);
	}
}

void	eat(t_phil *phil)
{
	get_current_time(phil);
	phil->t_last_eat = phil->t_current;
	if (phil->data->died == false && phil->data->all_sated == false)
	{
		phil->status = IS_EATING;
		print_status(phil, IS_EATING);
		ft_usleep(phil, phil->data->t_eat);
		pthread_mutex_unlock(&phil->data->forks[phil->fork_right]);
		pthread_mutex_unlock(&phil->data->forks[phil->fork_left]);
	}
}

void	ph_sleep(t_phil *phil)
{
	phil->meals++;
	phil->status = FREE;
	print_status(phil, IS_SLEEPING);
	if (phil->data->died == false && phil->data->all_sated == false)
		ft_usleep(phil, phil->data->t_sleep);
}

void	think(t_phil *phil)
{
	if (phil->data->died == false && phil->data->all_sated == false)
	{
		phil->status = FREE;
		if (phil->data->died == false)
			print_status(phil, IS_THINKING);
	}
}

