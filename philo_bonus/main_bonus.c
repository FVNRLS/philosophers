/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:16:57 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 17:34:56 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/philo_bonus.h"

/*
 * Each philosopher is a child process defined in the phil structure.
 * The forks are initialized as semaphores.
 * The parsed arguments and semaphores, are stored in the data structure
 * copied from each child process.
 * After simulation, the semaphores are destroyed.
 * */
int	main(int argc, char **argv)
{
	t_data		data;
	t_args		args;

	data.args = &args;
	args.ac = argc;
	args.av = argv;
	parse_input(&data);
	init_semaphores(&data);
	run_simulation(&data);
	destroy_semaphores(&data);
	return (EXIT_SUCCESS);
}
