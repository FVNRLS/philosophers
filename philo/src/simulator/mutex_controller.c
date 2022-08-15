/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 15:30:02 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	init_mutexes(t_phil *phil)
{
	int	i;

	pthread_mutex_init(&phil->std_out, NULL);
	phil->forks = malloc((sizeof(pthread_mutex_t) * phil->n_phil));
	i = 0;
	while (i < phil->n_phil)
	{
		pthread_mutex_init(&phil->forks[i], NULL);
		i++;
	}
}

void	destroy_mutexes(t_phil *phil)
{
	int	i;

	pthread_mutex_destroy(&phil->std_out);
	i = 0;
	while (i < phil->n_phil)
	{
		pthread_mutex_destroy(&phil->forks[i]);
		i++;
	}
	free(phil->forks);
	phil->forks = NULL;
}