/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:11:48 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 19:46:26 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void check_leaks()
{
	system("leaks philosophers");
}

 int	main(int argc, char **argv)
 {
//	atexit(check_leaks);

	t_phil	phil;
	t_args	args;

	phil.args = &args;
	args.ac = argc;
	args.av = argv;

	parse_input(&phil);
//	init_forks();
//	init_phil(); //create threads with while loop


 	return (0);
 }
