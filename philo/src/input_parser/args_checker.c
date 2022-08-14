/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:31:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/14 13:20:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

//TODO: plan dependencies and edge cases: time to die vs eat and sleep and relations between

void	check_phil_num(t_phil *phil)
{
	phil->n_phil = (int)ft_atol(phil->args->av[1]);
	if (phil->n_phil < 1 || phil->n_phil > MAX_THREADS)
		print_error_exit(INVALID_NUMBER_OF_PHILOSOPHERS);
}

/*
 * Takes input time value in seconds in ms.
 * */
void	check_time_to_die(t_phil *phil)
{
	long	t_input;

	t_input = ft_atol(phil->args->av[2]);
	if (t_input < 1)
		print_error_exit(INVALID_TIME_TO_DIE);
	phil->t_die = t_input;
}

void	check_time_to_eat(t_phil *phil)
{
	long	t_input;

	t_input = ft_atol(phil->args->av[3]);
	if (t_input < 1)
		print_error_exit(INVALID_TIME_TO_EAT);
	phil->t_eat = t_input;
	if (phil->t_eat >= phil->t_die)
		print_error_exit(INVALID_TIME_TO_EAT);
}

void	check_time_to_sleep(t_phil *phil)
{
	long	t_input;

	t_input = ft_atol(phil->args->av[4]);
	if (t_input < 1)
		print_error_exit(INVALID_TIME_TO_SLEEP);
	phil->t_sleep = t_input;
	if (phil->t_sleep >= phil->t_die)
		print_error_exit(INVALID_TIME_TO_SLEEP);
}

//TODO: set relations here
void	check_number_times_eat(t_phil *phil)
{
	phil->n_eat = ft_atol(phil->args->av[5]);
	if (phil->n_eat < 1)
		print_error_exit(INVALID_NUMBER_TIMES_EAT);
	if ((phil->n_eat * phil->t_eat) > phil->t_die)
		print_error_exit(INVALID_NUMBER_TIMES_EAT);
}
