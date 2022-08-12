/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:34:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 16:42:27 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"


static void	check_input(t_phil *phil)
{
	if (phil->args->ac != 6)
		print_error(WRONG_NUMBER_OF_ARGUMENTS);
//	else if (phil->args->av)
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
	check_input(phil);
}
