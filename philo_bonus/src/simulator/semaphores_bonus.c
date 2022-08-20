/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/20 11:16:14 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

static void	destroy_sem_stdout(t_data *data)
{
	if (!data->std_out)
		exit(EXIT_FAILURE);
	sem_close(data->std_out);
	sem_unlink("/tmp/.std_out");
	data->std_out = NULL;
}

static void destroy_sem_forks(t_data *data)
{
	if (!data->forks)
		exit(EXIT_FAILURE);
	sem_close(data->forks);
	sem_unlink("/tmp/.forks");
	data->forks = NULL;
}

void	destroy_semaphores(t_data *data)
{
	destroy_sem_stdout(data);
	destroy_sem_forks(data);
}

void	init_semaphores(t_data *data)
{
	data->std_out = sem_open("/tmp/.std_out", O_CREAT, RIGHTS, 1);
	if (!data->std_out)
		exit(EXIT_FAILURE);
	data->forks = sem_open("/tmp/.forks", O_CREAT, RIGHTS, data->n_phil);
	if (!data->forks)
	{
		destroy_sem_stdout(data);
		exit(EXIT_FAILURE);
	}
}
