/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/20 15:49:22 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

void	take_forks(t_phil *phil)
{
	if (phil->died == false)
	{
		sem_wait(phil->data->forks);
		print_status(phil, FORK_TAKEN);
	}
	if (phil->died == false)
	{
		sem_wait(phil->data->forks);
		print_status(phil, FORK_TAKEN);
	}
}

void	eat(t_phil *phil)
{
	get_current_time(phil);
	phil->t_last_eat = phil->t_current;
	if (phil->died == false)
	{
		print_status(phil, IS_EATING);
		ft_usleep(phil, phil->data->t_eat);
		sem_post(phil->data->forks);
		sem_post(phil->data->forks);
	}
}

void	ph_sleep(t_phil *phil)
{
	phil->status = IS_SLEEPING;
	print_status(phil, IS_SLEEPING);
	if (phil->died == false)
		ft_usleep(phil, phil->data->t_sleep);
}

void	think(t_phil *phil)
{
	if (phil->died == false)
	{
		if (phil->died == false)
			print_status(phil, IS_THINKING);
	}
}

