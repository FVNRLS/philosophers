/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_invalid_chars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:54:50 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 17:26:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*
	Check for invalid characters inside the provided unconverted argument.
	Set error flag to true if:
		1) No argument provided (string is empty).
		2) more than 1 minus sign was found.
		3) The argument is not a digit.
*/
bool	ft_check_invalid_chars(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
	{
		print_error(INVALID_CHARACTERS_FOUND);
		return (false);
	}
	if (str[i] == '-')
		i++;
	if (str[0] == '-' && str[1] == '\0')
	{
		print_error(INVALID_CHARACTERS_FOUND);
		return (false);
	}
	while (str[i] != '\0')
	{
		if (ft_is_digit(str[i]) == false)
		{
			print_error(INVALID_CHARACTERS_FOUND);
			return (false);
		}
		i++;
	}
	return (true);
}
