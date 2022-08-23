/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:12:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 13:58:05 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./actions.h"
# include "./error.h"
# include "./tools.h"

//INPUT PARSER
int		parse_input(t_data *data);
bool	check_phil_num(t_data *data);
bool	check_time_to_die(t_data *data);
bool	check_time_to_eat(t_data *data);
bool	check_time_to_sleep(t_data *data);
bool	check_number_times_eat(t_data *data);

//SIMULATION FUNCTIONS
int		run_simulation(t_data *data);
void	watch_phils(t_phil *phil);
void	put_all_forks(t_data *data);
void 	check_if_sated(t_phil *phil);
void	get_time_diff(t_phil *phil);
void	get_current_time(t_phil *phil);
void	get_time_diff(t_phil *phil);

//MUTEX (FORKS) CONTROLLER
int		init_mutexes(t_data *data);
void	destroy_mutexes(t_data *data);

#endif
