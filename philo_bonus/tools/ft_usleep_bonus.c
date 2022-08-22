/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:21:22 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/21 13:17:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo_bonus.h"

void   ft_usleep(t_phil *phil, long ms)
{
	struct timeval	now;
	struct timeval	start;
	long			i;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	i = 0;
	while(i < ms && phil->died == false)
	{
		gettimeofday(&now, NULL);
		i = ((now.tv_sec - start.tv_sec) * 1000) + ((now.tv_usec - start.tv_usec) / 1000);
		usleep(200);
	}
}