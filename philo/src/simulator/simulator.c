/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/14 17:25:54 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	simulate_phil(t_phil *phil, int index)
{
	take_fork(phil, index);
	eat(phil, index);
	ph_sleep(phil, index);
	think(phil, index);
}

void	*start_phil(void *arg)
{
	t_phil 		*phil;
	int			index;

	phil = &(*(t_phil*)arg);
	phil->index++;
	index = phil->index;
	phil->tstamp->res_us = 0;
	while (phil->phil_died == false)
		simulate_phil(phil, index);
	return (NULL);
}

void	init_phils(t_phil *phil)
{
	phil->phil = malloc((sizeof(int) * phil->n_phil));
	phil->phil_died = false;
	phil->die_msg_displayed = false;
	phil->index = 0;
}

void	create_phils(t_phil *phil)
{
	int i;

	i = 0;
	while (i < phil->n_phil)
	{
		if (pthread_create(&phil->phil[i], NULL, &start_phil, phil) != 0)
		{
			free(phil->phil);
			phil->phil = NULL;
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < phil->n_phil)
	{
		if (pthread_join(phil->phil[i], NULL) != 0)
		{
			free(phil->phil);
			phil->phil = NULL;
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	start_simulation(t_phil *phil)
{

	init_phils(phil);
	create_phils(phil);
	print_input_data(phil); //del!
	free(phil->phil);
	phil->phil = NULL;
	return (EXIT_SUCCESS);
}