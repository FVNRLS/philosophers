/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:18:11 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 15:48:21 by rmazurit         ###   ########.fr       */
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

# define MAX_THREADS 2000

typedef struct s_args
{
	int		ac;
	char	**av;
}		t_args;

typedef struct s_data
{
	int				n_phil;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			min_meals;
	long			t_start;
	bool			died;
	int				n_sated;
	pthread_mutex_t	*forks;
	pthread_mutex_t	std_out;
	struct timeval	time;
	t_args			*args;
}		t_data;

typedef struct s_phil
{
	pthread_t		*thread;
	int				id;
	int				status;
	bool			sated;
	int				fork_left;
	int				fork_right;
	long			t_current;
	long			t_last_eat;
	long			t_diff;
	int				meals;
	t_data			*data;
}		t_phil;

#endif
