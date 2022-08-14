/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:12:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/14 13:27:47 by rmazurit         ###   ########.fr       */
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

typedef struct s_args
{
	int 	ac;
	char 	**av;
} 		t_args;

typedef struct s_tstamps
{
	int		t_last;
	int 	t_current;
	int 	diff;
	long 	res_us;
	long 	res_ms;
}		t_tstamps;

typedef struct s_phil
{
	pthread_t 		*phil;
	pthread_mutex_t fork;
	int				index;
	int				n_phil;
	long			t_die;
	long 			t_eat;
	long			t_sleep;
	long			n_eat;
	bool			phil_died;
	struct timeval	t_current;
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


//FORKS MANAGER
void	init_fork(t_phil *phil);
void	destroy_fork(t_phil *phil);

//PHILOSOPHERS MANAGER
int		init_phils(t_phil *phil);


#endif
