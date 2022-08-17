/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/17 11:40:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

int	init_mutexes(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->std_out, NULL);
	data->forks = malloc((sizeof(pthread_mutex_t) * data->n_phil));
	if (!data->forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->n_phil)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

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