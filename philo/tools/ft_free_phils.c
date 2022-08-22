/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_phils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:52:57 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/19 14:56:23 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/* free the allocated memory for the philosophers array*/
void	ft_free_phils(t_phil *phil)
{
	free(phil->thread);
	phil->thread = NULL;
	free(phil);
	phil = NULL;
}
