/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:47:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 16:21:12 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

/* Kills all child processes. */
static void	kill_all_procs(t_phil *phil)
{
	int	i;

	i = 0;
	while (i < phil->data->n_phil)
	{
		kill(phil->proc[i], SIGKILL);
		i++;
	}
}

/*
 * Runs continuously in the background of every child process.
 * Checks if the philosopher has died.
 * If yes - the 'died' flag is set to true and the simulation is stopped.
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
			}
		}
	}
}

/*
 * Check if the number of meals has reached the minimum number of meals.
 * If yes, set the 'sated' flag to true.
 * If the user has not specified min_meals, the number of meals will always be 0
 * and the 'sated' flag will always be false.
 * In this case, the program can only end if any of the philosopher dies.
 * */
void	check_if_sated(t_phil *phil)
{
	if (phil->data->min_meals == 0)
		phil->sated = false;
	else if (phil->meals >= phil->data->min_meals)
		phil->sated = true;
}

/*
 * Hardcoded solution if the user enters the number 1 as the first argument
 * (number of philosophers).
 * The philosopher must take only one fork, but must not start eating and
 * dies instantly.
 * */
static void	check_if_lonely(t_phil *phil)
{
	if (phil->data->n_phil == 1)
	{
		print_status(phil, FORK_TAKEN);
		ft_usleep(phil, phil->data->t_die);
		print_status(phil, PHIL_DIED);
		kill(phil->proc[0], SIGKILL);
	}
}

/*
 * The watcher runs in the background in the parent process and is started after
 * the initialization and start of the child processes.
 * Watcher waits for exit of ANY the children and catches the exit code status.
 * The parameter -1 in the waitpid function indicates that the parent process
 * waits for exit of any child.
 * The wait continues either until all children have exited with exit code
 * PHIL_SATED or until one of the children dies (exit code PHIL_DIED).
 * */
void	watch_phils(t_phil *phil)
{
	int	status;
	int	i;

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
				kill_all_procs(phil);
				return ;
			}
		}
	}
}
