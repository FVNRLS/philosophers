/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:18:11 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 17:18:11 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>

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
	pthread_mutex_t	index_incr;
	struct timeval	time;
	t_args			*args;
	t_tstamps 		*tstamp;
}		t_phil;

#endif
