/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:34:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 20:05:50 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

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
	int 	i;
	char 	*arg;
//	if (phil->args->ac != 6)
//		print_error_exit(INVALID_NUMBER_OF_ARGUMENTS);
	gettimeofday(&phil->t_current, NULL);
	phil->t_start = phil->t_current.tv_usec;
	printf("start time: %d\n", phil->t_current.tv_usec);
	i = 1;
	while (i < 3) // i < 6
	{
		arg = phil->args->av[i];
		ft_check_invalid_chars(arg);
		i++;
	}
	check_phil_num(phil);
	check_time_to_die(phil);
	check_time_to_eat(phil);
}
