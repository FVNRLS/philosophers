/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_invalid_chars_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:54:50 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 11:46:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo_bonus.h"

/*
	Check for invalid characters inside the provided unconverted argument.
	Set error flag to true if:
		1) No argument provided (string is empty).
		2) more than 1 minus sign was found.
		3) The argument is not a digit.
*/
void	ft_check_invalid_chars(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
	{
		print_error(INVALID_CHARACTERS_FOUND);
		exit(EXIT_FAILURE);
	}
	if (str[i] == '-')
		i++;
	if (str[0] == '-' && str[1] == '\0')
	{
		print_error(INVALID_CHARACTERS_FOUND);
		exit(EXIT_FAILURE);
	}
	while (str[i] != '\0')
	{
		if (ft_is_digit(str[i]) == false)
		{
			print_error(INVALID_CHARACTERS_FOUND);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}