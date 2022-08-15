/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:21:22 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 11:40:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void   ft_usleep(long ms)

{
	struct timeval	now;
	struct timeval	start;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	while((((now.tv_sec - start.tv_sec) * 1000) +
		((now.tv_usec - start.tv_usec) / 1000)) < ms)
	{
		usleep(10);
		gettimeofday(&now, NULL);
	}
}
