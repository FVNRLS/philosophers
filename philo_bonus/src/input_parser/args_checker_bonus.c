/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:31:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 15:26:11 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

/*
 * Checks the first argument and stores its value as the number of philosophers.
 * If the value is invalid, the program is terminated with error code 1.
 * */
void	check_phil_num(t_data *data)
{
	data->n_phil = (int)ft_atol(data->args->av[1]);
	if (data->n_phil < 1)
	{
		print_error(INVALID_NUMBER_OF_PHILOSOPHERS);
		exit(EXIT_FAILURE);
	}
}

/*
 * Checks the second argument and stores its value as time to die (t_die).
 * If the value is invalid, the program is terminated with error code 1.
 * */
void	check_time_to_die(t_data *data)
{
	data->t_die = ft_atol(data->args->av[2]);
	if (data->t_die < 1)
	{
		print_error(INVALID_TIME_TO_DIE);
		exit(EXIT_FAILURE);
	}
}

/*
 * Checks the third argument and stores its value as time to eat (t_eat).
 * If the value is invalid, the program is terminated with error code 1.
 * */
void	check_time_to_eat(t_data *data)
{
	data->t_eat = ft_atol(data->args->av[3]);
	if (data->t_eat < 1)
	{
		print_error(INVALID_TIME_TO_EAT);
		exit(EXIT_FAILURE);
	}
}

/*
 * Checks the fourth argument and stores its value as time to sleep (t_sleep)
 * If the value is invalid, the program is terminated with error code 1.
 * */
void	check_time_to_sleep(t_data *data)
{
	data->t_sleep = ft_atol(data->args->av[4]);
	if (data->t_sleep < 1)
	{
		print_error(INVALID_TIME_TO_SLEEP);
		exit(EXIT_FAILURE);
	}
}

/*
 * Checks the fifth argument and stores its value as min. num. of meals
 * (min_meals).
 * If the value is invalid, the program is terminated with error code 1.
 * */
void	check_number_times_eat(t_data *data)
{
	data->min_meals = ft_atol(data->args->av[5]);
	if (data->min_meals < 1)
	{
		print_error(INVALID_NUMBER_TIMES_EAT);
		exit(EXIT_FAILURE);
	}
}
