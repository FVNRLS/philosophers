/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:11:48 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/14 11:00:16 by rmazurit         ###   ########.fr       */
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

	t_phil		phil;
	t_args		args;
	t_tstamps	tstamp;

	phil.tstamp = &tstamp;
	phil.args = &args;
	args.ac = argc;
	args.av = argv;

	parse_input(&phil);
	pthread_mutex_init(&phil.fork, NULL);
	start_simulation(&phil);
	pthread_mutex_destroy(&phil.fork);


 	return (EXIT_SUCCESS);
 }
