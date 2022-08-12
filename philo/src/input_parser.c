/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:34:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 17:41:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"


static void	check_phil_num(t_phil *phil)
{
	char *str;

	str = phil->args->av[1];
	ft_check_invalid_chars(str);
	phil->n_phil = ft_atol(str);
	if (phil->n_phil < 1 || phil->n_phil > MAX_THREADS)
		print_error_exit(INVALID_NUMBER_OF_PHILOSOPHERS);
}


/*
 * Arguments:
 * number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * [number_of_times_each_philosopher_must_eat]
 * */
void	parse_input(t_phil *phil)
{
	if (phil->args->ac != 6)
		print_error_exit(INVALID_NUMBER_OF_ARGUMENTS);
	check_phil_num(phil);
}
