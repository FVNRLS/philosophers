/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:34:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 11:46:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

/*
 * Parses and checks the arguments.
 * */
static void	parse_args(t_data *data)
{
	check_phil_num(data);
	check_time_to_die(data);
	check_time_to_eat(data);
	check_time_to_sleep(data);
	data->min_meals = 0;
	if (data->args->ac == 6)
		check_number_times_eat(data);
}

/*
 * Checks the number of arguments and if valid, parses the arguments one by one.
 * Checks if the input arguments contain any invalid characters
 * 		-> if yes, program exits with error code.

 * Arguments:
 * number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * [number_of_times_each_philosopher_must_eat]
 * */
void parse_input(t_data *data)
{
	int 	i;
	char 	*arg;

	if (data->args->ac < 5 ||  data->args->ac > 6)
	{
		print_error(INVALID_NUMBER_OF_ARGUMENTS);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < data->args->ac)
	{
		arg = data->args->av[i];
		ft_check_invalid_chars(arg);
		i++;
	}
	parse_args(data);
}
