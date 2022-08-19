/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:34:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/17 11:40:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

static bool	parse_args(t_data *data)
{
	bool	phil_num_valid;
	bool	t_to_die_valid;
	bool	t_to_eat_valid;
	bool	t_to_sleep_valid;
	bool	n_times_eat_valid;

	phil_num_valid = check_phil_num(data);
	t_to_die_valid = check_time_to_die(data);
	t_to_eat_valid = check_time_to_eat(data);
	t_to_sleep_valid = check_time_to_sleep(data);
	data->min_meals = 0;
	if (phil_num_valid == false || t_to_die_valid == false ||
	t_to_eat_valid == false || t_to_sleep_valid == false)
		return (false);
	if (data->args->ac == 6)
	{
		n_times_eat_valid = check_number_times_eat(data);
		if (n_times_eat_valid == false)
			return (false);
	}
	return (true);
}

/*
 * Arguments:
 * number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * [number_of_times_each_philosopher_must_eat]
 * */
int	parse_input(t_data *data)
{
	int 	i;
	char 	*arg;
	bool	chars_valid;
	bool	input_valid;

	if (data->args->ac < 5 ||  data->args->ac > 6)
	{
		print_error(INVALID_NUMBER_OF_ARGUMENTS);
		return (EXIT_FAILURE);
	}
	i = 1;
	while (i < data->args->ac)
	{
		arg = data->args->av[i];
		chars_valid = ft_check_invalid_chars(arg);
		if (chars_valid == false)
			return (EXIT_FAILURE);
		i++;
	}
	input_valid = parse_args(data);
	if (input_valid == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
