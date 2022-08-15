/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:12:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 17:57:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./actions.h"
# include "./error.h"
# include "./tools.h"

# define MAX_THREADS	10240

//INPUT PARSER
void	parse_input(t_phil *phil);
void	check_phil_num(t_phil *phil);
void	check_time_to_die(t_phil *phil);
void	check_time_to_eat(t_phil *phil);
void	check_time_to_sleep(t_phil *phil);
void	check_number_times_eat(t_phil *phil);

//SIMULATION FUNCTIONS
int		start_simulation(t_phil *phil);
bool	check_phil_died(t_phil *phil, t_id *id);
void	get_current_time(t_phil *phil);

//MUTEX (FORKS) CONTROLLER
void	init_mutexes(t_phil *phil);
void	destroy_mutexes(t_phil *phil);


#endif
