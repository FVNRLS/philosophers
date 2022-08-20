/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/20 13:12:01 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

static void	simulate(t_phil *phil)
{
	if (phil->id % 2 == 0)
		ft_usleep(phil, (phil->data->t_eat / 2));
	while (phil->data->died == false && phil->data->all_sated == false)
	{
		take_forks(phil);
		eat(phil);
		ph_sleep(phil);
		think(phil);
	}
}

static void	init_start_params(t_phil *phil)
{
	phil->t_last_eat = 0;
	phil->meals = 0;
	get_current_time(phil);
	phil->t_start = phil->t_current;
	phil->data->died = false;
	phil->data->all_sated = false;
}

static void	run_procs(t_phil *phil)
{
	int i;

	i = 0;
	init_start_params(phil);
	while (i < phil->data->n_phil)
	{
		phil->id = i + 1;
		simulate(phil);
		phil->proc = fork();
		i++;
	}

}


void	run_simulation(t_data *data)
{
	t_phil	phil;
	int		status;

	phil.data = data;


	run_procs(&phil);
	waitpid(-1, &status, 0);
	if (status != 0)
	{
		destroy_semaphores(data);
		kill(0, SIGQUIT);
		exit(EXIT_FAILURE);
	}
	kill(0, SIGQUIT);
//	watch_phils(phil);
}