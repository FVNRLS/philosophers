/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/16 12:01:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	take_forks(t_phil *phil, t_id *id)
{
	pthread_mutex_lock(&phil->forks[id->fork_left]);
	if (phil->died == false)
		print_status(phil, id, LEFT_FORK_TAKEN);
	pthread_mutex_lock(&phil->forks[id->fork_right]);
	if (phil->died == false)
		print_status(phil, id, RIGHT_FORK_TAKEN);
}

void	eat(t_phil *phil, t_id *id)
{
	if (phil->died == false)
		print_status(phil, id, IS_EATING);
	ft_usleep(phil->t_eat);
	pthread_mutex_unlock(&phil->forks[id->fork_right]);
	pthread_mutex_unlock(&phil->forks[id->fork_left]);
	get_current_time(phil);
	phil->tstamp->t_last_eat = phil->tstamp->t_current;
}

void	ph_sleep(t_phil *phil, t_id *id)
{
	if (phil->died == false)
		print_status(phil, id, IS_SLEEPING);
	ft_usleep(phil->t_sleep);
}

void	think(t_phil *phil, t_id *id)
{
	if (phil->died == false)
		print_status(phil, id, IS_THINKING);
}