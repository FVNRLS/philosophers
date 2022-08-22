/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/21 19:57:37 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

void	take_forks(t_phil *phil)
{
	phil->status = FREE;
	sem_wait(phil->data->fork);
	print_status(phil, FORK_TAKEN);
	sem_wait(phil->data->fork);
	print_status(phil, FORK_TAKEN);
}

void	eat(t_phil *phil)
{
	get_current_time(phil);
	phil->t_last_eat = phil->t_current;

		phil->status = IS_EATING;
		print_status(phil, IS_EATING);
		ft_usleep(phil, phil->data->t_eat);
		sem_post(phil->data->fork);
		sem_post(phil->data->fork);
	}
}

void	ph_sleep(t_phil *phil)
{
	phil->status = FREE;
	if (phil->died == false)
	{
		print_status(phil, IS_SLEEPING);
		ft_usleep(phil, phil->data->t_sleep);
	}
}

void	think(t_phil *phil)
{
	phil->status = FREE;
	if (phil->died == false)
		print_status(phil, IS_THINKING);
}

