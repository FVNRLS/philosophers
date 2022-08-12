/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:45:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 19:52:34 by rmazurit         ###   ########.fr       */
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
	exit(EXIT_FAILURE);
}