/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:31:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/17 11:06:23 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

//TODO: plan dependencies and edge cases: time to die vs eat and sleep and relations between

bool	check_phil_num(t_data *data)
{
	data->n_phil = (int)ft_atol(data->args->av[1]);
	if (data->n_phil < 1 || data->n_phil > MAX_THREADS)
	{
		print_error(INVALID_NUMBER_OF_PHILOSOPHERS);
		return (false);
	}
	return (true);
}

/*
 * Takes input time value in milliseconds.
 * */
bool	check_time_to_die(t_data *data)
{
	data->t_die = ft_atol(data->args->av[2]);
	if (data->t_die < 1)
	{
		print_error(INVALID_TIME_TO_DIE);
		return (false);
	}
	return (true);
}

bool	check_time_to_eat(t_data *data)
{
	data->t_eat = ft_atol(data->args->av[3]);
	if (data->t_eat < 1)
	{
		print_error(INVALID_TIME_TO_EAT);
		return (false);
	}
	return (true);
}

bool	check_time_to_sleep(t_data *data)
{
	data->t_sleep = ft_atol(data->args->av[4]);
	if (data->t_sleep < 1)
	{
		print_error(INVALID_TIME_TO_SLEEP);
		return (false);
	}
	return (true);
}

//TODO: set relations here
bool	check_number_times_eat(t_data *data)
{
	data->meals = ft_atol(data->args->av[5]);
	if (data->meals < 1)
	{
		print_error(INVALID_NUMBER_TIMES_EAT);
		return (false);
	}
	if ((data->meals * data->t_eat) > data->t_die)
	{
		print_error(INVALID_NUMBER_TIMES_EAT);
		return (false);
	}
	return (true);
}
