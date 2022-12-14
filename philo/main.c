/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:11:48 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 19:59:11 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/philo.h"

/*
 * Each philosopher is a thread defined in the phil structure.
 * The forks are initialized as mutexes.
 * The parsed arguments and mutexes, are stored in the data structure and all
 * threads have access to them.
 * After simulation, the mutexes are destroyed.
 * */
int	main(int argc, char **argv)
{
	t_data	data;
	t_args	args;
	int		exit_ret;

	data.args = &args;
	args.ac = argc;
	args.av = argv;
	exit_ret = parse_input(&data);
	if (exit_ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	exit_ret = init_mutexes(&data);
	if (exit_ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	exit_ret = run_simulation(&data);
	destroy_mutexes(&data);
	if (exit_ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
