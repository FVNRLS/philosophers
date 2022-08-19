/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:45:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/18 16:50:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo_bonus.h"

void	print_error(int error_key)
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
	else if (error_key == INVALID_TIME_TO_SLEEP)
		printf("Error: invalid time to sleep.");
	else if (error_key == INVALID_NUMBER_TIMES_EAT)
		printf("Error: invalid number of times to eat.");
}

void	print_status(t_phil *phil, int status)
{
	pthread_mutex_lock(&phil->data->std_out);
	get_current_time(phil);
	if (status == PHIL_DIED)
		printf("%ld %d died\n", phil->t_current, phil->id);
	if (phil->data->died == false)
	{
		if (status == FORK_TAKEN)
			printf("%ld %d has taken a fork\n", phil->t_current, phil->id);
		else if (status == IS_EATING)
			printf("%ld %d is eating\n", phil->t_current, phil->id);
		else if (status == IS_SLEEPING)
			printf("%ld %d is sleeping\n", phil->t_current, phil->id);
		else if (status == IS_THINKING)
			printf("%ld %d is thinking\n", phil->t_current, phil->id);
	}
	pthread_mutex_unlock(&phil->data->std_out);
}