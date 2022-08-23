/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 15:08:15 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
 * Initializes two mutexes with protection:
		std_out: to write to stdout to avoid the encoded output.
		forks: stands for the number of forks (init number of philosophers).
*/
int	init_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->std_out, NULL) != 0)
		return (EXIT_FAILURE);
	data->forks = malloc((sizeof(pthread_mutex_t) * data->n_phil));
	if (!data->forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->n_phil)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	put_all_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_phil)
	{
		pthread_mutex_unlock(&data->forks[i]);
		i++;
	}
}

/* Destroys/frees the initialized mutexes.*/
void	destroy_mutexes(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->std_out);
	i = 0;
	while (i < data->n_phil)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL;
}
