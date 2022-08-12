/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:45:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 17:02:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	print_error_exit(int	error_key)
{
	if (error_key == INVALID_NUMBER_OF_ARGUMENTS)
		printf("Error: invalid number of arguments.");
	else if (error_key == INVALID_NUMBER_OF_PHILOSOPHERS)
		printf("Error: invalid number of philosophers.");
	exit(EXIT_FAILURE);
}