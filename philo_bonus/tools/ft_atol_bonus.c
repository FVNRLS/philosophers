/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:47:59 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 11:46:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo_bonus.h"

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	while (str[i] != '\0')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	res = res * sign;
	return (res);
}