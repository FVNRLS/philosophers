/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/20 16:16:34 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

static void	destroy_sem_stdout(t_data *data)
{
	if (!data->std_out)
		exit(EXIT_FAILURE);
	sem_close(data->std_out);
	sem_unlink("/tmp/std_out");
	data->std_out = NULL;
}

static void destroy_sem_forks(t_data *data)
{
	if (!data->fork)
		exit(EXIT_FAILURE);
	sem_close(data->fork);
	sem_unlink("/tmp/forks");
	data->fork = NULL;
}

void	destroy_semaphores(t_data *data)
{
	destroy_sem_stdout(data);
	destroy_sem_forks(data);
}

void	init_semaphores(t_data *data)
{
	sem_unlink("/tmp/std_out");
	sem_unlink("/tmp/forks");
	data->std_out = sem_open("/tmp/std_out", O_CREAT, RIGHTS, 1);
	if (!data->std_out)
		exit(EXIT_FAILURE);
	data->fork = sem_open("/tmp/forks", O_CREAT, RIGHTS, data->n_phil);
	if (!data->fork)
	{
		destroy_sem_stdout(data);
		exit(EXIT_FAILURE);
	}
}
