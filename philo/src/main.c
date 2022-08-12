/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:11:48 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 16:38:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

 int	main(int argc, char **argv)
 {
	t_phil	phil;
	t_args	args;

	phil.args = &args;
	args.ac = argc;
	args.av = argv;

	parse_input(&phil);
	gettimeofday(&phil.t_current, NULL);
 	printf("microsec.: %d\n", phil.t_current.tv_usec);
//	init_forks();
//	init_phil(); //create threads with while loop


 	return (0);
 }
