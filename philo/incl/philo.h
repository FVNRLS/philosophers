/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:12:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 15:53:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>

# include "./error.h"
# include "./tools.h"

# define MAX_THREADS		10240

typedef struct s_id
{
	int	phil;
	int fork_left;
	int fork_right;
} 		t_id;

typedef struct s_args
{
	int 	ac;
	char 	**av;
} 		t_args;

typedef struct s_tstamps
{
	long	t_last_eat;
	long 	t_current;
	long 	t_diff;
}		t_tstamps;

typedef struct s_phil
{
	pthread_t 		*phil;
	pthread_mutex_t *forks;
	pthread_mutex_t std_out;
	int				index;
	int				n_phil;
	long			t_die;
	long 			t_eat;
	long			t_sleep;
	long			n_eat;
	bool			died;
	bool			die_msg_displayed;
	struct timeval	time;
	t_args			*args;
	t_tstamps 		*tstamp;
}		t_phil;

//INPUT PARSER
void	parse_input(t_phil *phil);
void	check_phil_num(t_phil *phil);
void	check_time_to_die(t_phil *phil);
void	check_time_to_eat(t_phil *phil);
void	check_time_to_sleep(t_phil *phil);
void	check_number_times_eat(t_phil *phil);

//SIMULATION FUNCTIONS
int		start_simulation(t_phil *phil);
bool 	check_phil_died(t_phil *phil);
void	get_current_time(t_phil *phil);
void	print_input_data(t_phil *phil);

//PHILOSOPHERS ACTIONS
void	take_forks(t_phil *phil, t_id *id);
void	eat(t_phil *phil, t_id *id);
void	ph_sleep(t_phil *phil, t_id *id);
void	think(t_phil *phil, t_id *id);

//MUTEX (FORKS) CONTROLLER
void	init_mutexes(t_phil *phil);
void	destroy_mutexes(t_phil *phil);


#endif
