/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:16:57 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/19 17:19:52 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/philo_bonus.h"

void check_leaks()
{
	system("leaks philosophers");
}

int	main(int argc, char **argv)
{
//	atexit(check_leaks);
	t_data		data;
	t_args		args;
	int 		exit_ret;

	data.args = &args;
	args.ac = argc;
	args.av = argv;
	exit_ret = parse_input(&data);
	if (exit_ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
