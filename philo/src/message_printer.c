/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:45:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/16 12:47:12 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	print_error_exit(int error_key)
{
	if (error_key == INVALID_NUMBER_OF_ARGUMENTS)
		printf("Error: invalid number of arguments.");
	else if (error_key == INVALID_CHARACTERS_FOUND)
		printf("Error: invalid characters found.");
	else if (error_key == INVALID_NUMBER_OF_PHILOSOPHERS)
		printf("Error: invalid number of philosophers.");
	else if (error_key == INVALID_TIME_TO_DIE)
		printf("Error: invalid time to die.");
	else if (error_key == INVALID_TIME_TO_EAT)
		printf("Error: invalid time to eat.");
	else if (error_key == INVALID_NUMBER_TIMES_EAT)
		printf("Error: invalid number of times to eat.");
	exit(EXIT_FAILURE);
}

void	print_status(t_phil *phil, t_id *id, int status)
{
	pthread_mutex_lock(&phil->std_out);
	get_current_time(phil);
	if (status == PHIL_DIED)
		printf("%ld %d died\n", phil->tstamp->t_current, phil->index);
	else if (status == LEFT_FORK_TAKEN || status == RIGHT_FORK_TAKEN)
		printf("%ld %d has taken a fork\n", phil->tstamp->t_current, id->phil);
	else if (status == IS_EATING)
		printf("%ld %d is eating\n", phil->tstamp->t_current, id->phil);
	else if (status == IS_SLEEPING)
		printf("%ld %d is sleeping\n", phil->tstamp->t_current, id->phil);
	else if (status == IS_THINKING)
		printf("%ld %d is thinking\n", phil->tstamp->t_current, id->phil);
	pthread_mutex_unlock(&phil->std_out);
}