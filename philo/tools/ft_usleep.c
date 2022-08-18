/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:21:22 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/18 17:39:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void   ft_usleep(long ms)
{
	struct timeval	now;
	struct timeval	start;
	long			i;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	i = 0;
	while(i < ms)
	{
		gettimeofday(&now, NULL);
		i = ((now.tv_sec - start.tv_sec) * 1000) + ((now.tv_usec - start.tv_usec) / 1000);
		usleep(300);
	}
}
