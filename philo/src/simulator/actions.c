/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 13:20:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
 *	The forks (mutexes) are from left and right side of each philosopher.
 *	A philosopher has access only to left and right fork.
 *	Left fork is always indexed as the philosopher's ID and the right is ID+1.
 *	Exception: the last phil. with left fork = phil ID and right fork with ID 1.
 *	A philosopher takes the forks by calling pthread_mutex_lock function.
 *	After each take of a fork, a message is printed.
 *	If the fork cannot be taken, the philosopher waits here until it's free.
 *	Each philosopher must take exactly 2 forks before he can start eating.
 *	The action happens until any philosopher is dead or philosophers are sated.
 * */
void	take_forks(t_phil *phil)
{
	if (phil->data->died == false)
	{
		phil->status = FREE;
		pthread_mutex_lock(&phil->data->forks[phil->fork_left]);
		print_status(phil, FORK_TAKEN);
		pthread_mutex_lock(&phil->data->forks[phil->fork_right]);
		print_status(phil, FORK_TAKEN);
	}
}

/*
 * The philosopher begins to eat when he has taken 2 forks and is not dead.
 * At the beginning the current time is fixed. This is always the time from
 * which the philosopher starts to eat (t_last_eat).
 * The time refreshes itself with each eating and is used as a reference for
 * the comparison against the time to die (t_die).
 * The status is set to IS_EATING and is used by the watcher as an indicator
 * that the philosopher should not be checked while eating.
 * After eating, the philosopher puts the 2 forks back, so the next
 * philosophers from right and left can use the forks.
 * To secure the program against deadlock the putting order is:
 * put back right fork, then the left fork, because the next philosopher will
 * firstly always search for the left.
 * */
void	eat(t_phil *phil)
{
	get_current_time(phil);
	phil->t_last_eat = phil->t_current;
	if (phil->data->died == false)
	{
		phil->status = IS_EATING;
		print_status(phil, IS_EATING);
		ft_usleep(phil, phil->data->t_eat);
		pthread_mutex_unlock(&phil->data->forks[phil->fork_right]);
		pthread_mutex_unlock(&phil->data->forks[phil->fork_left]);
	}
}

/*
 * After every meal, the philosopher starts to sleep.
 * The philosopher can die of starvation during sleep if the time initially of
 * the t_last_eat exceeds the t_die, so status FREE is set & checked by watcher.
 * */
void	ph_sleep(t_phil *phil)
{
	phil->status = FREE;
	print_status(phil, IS_SLEEPING);
	if (phil->data->died == false)
		ft_usleep(phil, phil->data->t_sleep);
}

/*
 * After sleeping, the philosopher begins to think.
 * The philosopher thinks as long as he does not get the opportunity to take the
 * first fork.
 * While thinking, the philosopher can die of starvation (status FREE).
 * */
void	think(t_phil *phil)
{
	if (phil->data->died == false)
	{
		phil->status = FREE;
		if (phil->data->died == false)
			print_status(phil, IS_THINKING);
	}
}
