/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:18:11 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 16:09:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>

typedef struct s_args
{
	int		ac;
	char	**av;
}		t_args;

typedef struct s_data
{
	int			n_phil;
	long		t_die;
	long		t_eat;
	long		t_sleep;
	long		min_meals;
	sem_t		*fork;
	sem_t		*std_out;
	t_args		*args;
}		t_data;

typedef struct s_phil
{
	pid_t		*proc;
	int			id;
	int			status;
	long		t_start;
	long		t_current;
	long		t_last_eat;
	long		t_diff;
	int			meals;
	bool		died;
	bool		sated;
	t_data		*data;
}		t_phil;

#endif
