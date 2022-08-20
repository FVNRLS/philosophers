/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/20 15:49:22 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

void	get_current_time(t_phil *phil)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	phil->t_current =
			((current.tv_sec * 1000) + (current.tv_usec / 1000)) - phil->t_start;
}

static void	get_time_diff(t_phil *phil)
{
	get_current_time(phil);
	phil->t_diff = phil->t_current - phil->t_last_eat;
}

void	check_death(t_phil *phil)
{
	get_time_diff(phil);
	if (phil->t_diff >= phil->data->t_die)
	{
		print_status(phil, PHIL_DIED);
		exit(PHIL_DIED);
	}

}

static void check_if_lonely(t_phil *phil)
{
	if (phil->data->n_phil == 1)
	{
		print_status(phil, FORK_TAKEN);
		print_status(phil, PHIL_DIED);
		kill(0, SIGINT);
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
		if (status == PHIL_SATED)
			i++;
		else if (status == PHIL_DIED || status == -1)
		{
			kill(0, SIGINT);
			break ;
		}
	}
}
