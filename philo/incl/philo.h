/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:12:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 19:42:10 by rmazurit         ###   ########.fr       */
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

# define MAX_THREADS				10240

# define LEFT_FORK_BUSY				1
# define RIGHT_FORK_BUSY			2
# define LEFT_FORK_FREE				3
# define RIGHT_FORK_FREE			4

typedef struct s_args
{
	int 	ac;
	char 	**av;
} 		t_args;

typedef struct s_phil
{
	long			n_phil;
	long			t_die;
	long 			t_eat;
	long			t_sleep;
	long			t_think;
	pthread_mutex_t fork_left;
	pthread_mutex_t fork_right;
	long			t_start;
	struct timeval	t_current;
	t_args			*args;
}		t_phil;

//INPUT PARSER
void	parse_input(t_phil *phil);
void	check_phil_num(t_phil *phil);
void	check_time_to_die(t_phil *phil);
void	check_time_to_eat(t_phil *phil);

#endif
