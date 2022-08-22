/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 12:39:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

/*
 * A routine watcher (thread) function, which is continuously running in the
 * background of every child process.
 *
 * */
void	check_death(t_phil *phil)
{
	while (phil->died == false)
	{
		if (phil->status == FREE)
		{
			get_time_diff(phil);
			if (phil->t_diff >= phil->data->t_die)
			{
				phil->died = true;
				print_status(phil, PHIL_DIED);
				exit(PHIL_DIED);
			}
		}
	}
}

void	check_if_sated(t_phil *phil)
{
	if (phil->data->min_meals == 0)
		phil->sated = false;
	else if (phil->meals >= phil->data->min_meals)
		phil->sated = true;
}

static void check_if_lonely(t_phil *phil)
{
	if (phil->data->n_phil == 1)
	{
		print_status(phil, FORK_TAKEN);
		print_status(phil, PHIL_DIED);
		kill(0, SIGKILL);
	}
}

void	watch_phils(t_phil *phil)
{
	int		status;
	int 	i;
	
	check_if_lonely(phil);
	i = 0;
	while (i < phil->data->n_phil)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			if (status == PHIL_SATED)
				i++;
			else if (status == PHIL_DIED || status == EXIT_FAILURE)
			{
				kill(0, SIGKILL);
				return ;
			}
		}
	}
}
