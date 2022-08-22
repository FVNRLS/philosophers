/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:43:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 16:01:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

/*
 *	The forks (fork semaphore) are in the middle of the table
 *		-> everyone has access to them.
 *	A philosopher (child process) takes the forks by calling sem_wait function.
 *	After each take of a fork, a message is printed.
 *	If the fork cannot be taken, the philosopher will wait here until one of the
 *	forks is free.
 *	Each philosopher must take exactly 2 forks before he can start eating.
 *	The action happens only if a philosopher is not dead.
 * */
void	take_forks(t_phil *phil)
{
	if (phil->died  == false)
	{
		phil->status = FREE;
		sem_wait(phil->data->fork);
		print_status(phil, FORK_TAKEN);
		sem_wait(phil->data->fork);
		print_status(phil, FORK_TAKEN);
	}
}

/*
 * The philosopher begins to eat when he has taken 2 forks and is not dead.
 * At the beginning the current time is fixed. This is always the time from
 * which the philosopher starts to eat (t_last_eat).
 * The time refreshes itself with each eating and is used as a reference for
 * the comparison against the time to die (t_die).
 * The status is set to IS_EATING and is used by the watcher thread inside the
 * child process as an indicator that the philosopher should not be killed while
 * eating (t_die is not checked).
 * After eating, the philosopher puts the 2 forks back.
 * */
void	eat(t_phil *phil)
{
	if (phil->died  == false)
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

/*
 * After every meal, the philosopher starts to sleep.
 * The philosopher can die of starvation during sleep if the time initially of
 * the t_last_eat exceeds the t_die.
 * */
void	ph_sleep(t_phil *phil)
{
	phil->status = FREE;
	if (phil->died == false)
	{
		print_status(phil, IS_SLEEPING);
		ft_usleep(phil, phil->data->t_sleep);
	}
}

/*
 * After sleeping, the philosopher begins to think.
 * The philosopher thinks as long as he does not get the opportunity to take the
 * first fork.
 * While thinking, the philosopher can die of starvation (status FREE).
 * */
void	think(t_phil *phil)
{
	phil->status = FREE;
	if (phil->died == false)
		print_status(phil, IS_THINKING);
}

