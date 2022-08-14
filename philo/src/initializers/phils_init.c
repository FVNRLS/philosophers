/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/14 14:34:09 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	print_input_data(t_phil *phil)
{
	printf("\nnum phil: 		%d\n", phil->n_phil);
	printf("time to die: 		%ld\n", phil->t_die);
	printf("time to eat: 		%ld\n", phil->t_eat);
	printf("time to sleep: 		%ld\n", phil->t_sleep);
	printf("num times to eat: 	%ld\n", phil->n_eat);
}

void	calc_res(t_phil *phil)
{
	t_tstamps	*tstamp;

	tstamp = phil->tstamp;
	if (tstamp->res_us == 0)
	{
		gettimeofday(&phil->t_current, NULL);
		tstamp->t_last = phil->t_current.tv_usec;
	}
	else
		tstamp->t_last = tstamp->t_current;
	gettimeofday(&phil->t_current, NULL);
	tstamp->t_current = phil->t_current.tv_usec;
	if (tstamp->t_current >= tstamp->t_last)
		tstamp->diff = tstamp->t_current - tstamp->t_last;
	else if (tstamp->t_current < tstamp->t_last)
		tstamp->diff = (1000000 - tstamp->t_last) + tstamp->t_current;
	tstamp->res_us += tstamp->diff;
	tstamp->res_ms = tstamp->res_us / 1000;
}

void 	check_kill_phil(t_phil *phil)
{
	gettimeofday(&phil->t_current, NULL);
	calc_res(phil);
	if (phil->tstamp->res_ms >= phil->t_die && phil->phil_died == false)
	{
		printf("%ld ms philosopher %d died!\n", phil->tstamp->res_ms, phil->index);
		print_input_data(phil);
		phil->phil_died = true;
		pthread_mutex_unlock(&phil->fork);
		pthread_exit(EXIT_SUCCESS);
	}
	else if (phil->phil_died == true)
	{
		pthread_mutex_unlock(&phil->fork);
		pthread_exit(EXIT_SUCCESS);
	}
}

void	take_fork(t_phil *phil, int index)
{
	pthread_mutex_lock(&phil->fork);
	check_kill_phil(phil);
	printf("%ld ms philosopher %d has taken a fork\n", phil->tstamp->res_ms, index);
}

void	eat(t_phil *phil, int index)
{
	int i;

	check_kill_phil(phil);
	printf("%ld ms philosopher %d is eating\n", phil->tstamp->res_ms, index);
	i = 0;
	while (i < phil->t_eat)
	{
		gettimeofday(&phil->t_current, NULL);
		calc_res(phil);
		check_kill_phil(phil);
		usleep(1000);
		i++;
	}
	pthread_mutex_unlock(&phil->fork);
}

void	simulate_phil(t_phil *phil, int index)
{
	take_fork(phil, index);
	eat(phil, index);
}

void	*create_phil(void *arg)
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

int	init_phils(t_phil *phil)
{
	int i;

	phil->phil = malloc((sizeof(int) * phil->n_phil));
	phil->phil_died = false;
	phil->index = 0;
	i = 0;
	while (i < phil->n_phil)
	{
		if (pthread_create(&phil->phil[i], NULL, &create_phil, phil) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < phil->n_phil)
	{
		if (pthread_join(phil->phil[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	free(phil->phil);
	phil->phil = NULL;
	return (EXIT_SUCCESS);
}