/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:16:57 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 11:46:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/philo_bonus.h"

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
