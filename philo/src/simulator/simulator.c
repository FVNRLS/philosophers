/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 16:05:23 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

static void	simulate_phil(t_phil *phil, t_id *id)
{
	check_phil_died(phil, id);
	take_forks(phil, id);
	eat(phil, id);
	ph_sleep(phil, id);
	think(phil, id);
	check_phil_died(phil, id);
}

void	*start_phil(void *arg)
{
	t_phil 		*phil;
	t_id		id;

	phil = &(*(t_phil*)arg);
	phil->index++;
	id.phil = phil->index;
	id.fork_left = id.phil;
	if (id.phil == phil->n_phil)
		id.fork_right = 1;
	else
		id.fork_right = id.phil + 1;
	while (phil->died == false)
		simulate_phil(phil, &id);
	return (NULL);
}

void	init_phils(t_phil *phil)
{
	phil->phil = malloc((sizeof(pthread_t) * phil->n_phil));
	phil->died = false;
	phil->die_msg_displayed = false;
	phil->index = 0;
}

static void	create_phils(t_phil *phil)
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
//	print_input_data(phil); //del!
	free(phil->phil);
	phil->phil = NULL;
	return (EXIT_SUCCESS);
}