/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:31:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 20:11:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	check_phil_num(t_phil *phil)
{
	phil->n_phil = ft_atol(phil->args->av[1]);
	if (phil->n_phil < 1 || phil->n_phil > MAX_THREADS)
		print_error_exit(INVALID_NUMBER_OF_PHILOSOPHERS);
	printf("num phil: 	%ld\n", phil->n_phil);
}

/*
 * Takes input time value in seconds and converts it to microseconds.
 * Calculates the time, when a philosopher should die in microseconds:
 * TIME_TO_DIE = STARTING_TIME + INPUT_TIME
 * */
void	check_time_to_die(t_phil *phil)
{
	long	t_input;

	t_input = ft_atol(phil->args->av[2]);
	if (t_input < 1)
		print_error_exit(INVALID_TIME_TO_DIE);
	t_input *= 1000000;
	phil->t_die = phil->t_start + t_input;
	printf("time to die: 	%ld\n", phil->t_die);
}

void	check_time_to_eat(t_phil *phil)
{
	long	t_input;

	t_input = ft_atol(phil->args->av[3]);
	if (t_input < 1)
		print_error_exit(INVALID_TIME_TO_EAT);
	t_input *= 1000000;
	phil->t_eat = phil->t_start + t_input;
	if (phil->t_eat >= phil->t_die)
		print_error_exit(INVALID_TIME_TO_EAT);
	printf("time to eat: 	%ld\n", phil->t_eat);
}