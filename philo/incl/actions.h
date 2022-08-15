/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:15:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/15 17:34:30 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ACTIONS_H
# define ACTIONS_H

# include "structs.h"

//STATES
# define LEFT_FORK_TAKEN		1
# define RIGHT_FORK_TAKEN		2
# define IS_EATING				3
# define IS_SLEEPING			4
# define IS_THINKING			5
# define PHIL_DIED				6

//PHILOSOPHERS ACTIONS
void	take_forks(t_phil *phil, t_id *id);
void	eat(t_phil *phil, t_id *id);
void	ph_sleep(t_phil *phil, t_id *id);
void	think(t_phil *phil, t_id *id);
void	print_status(t_phil *phil, t_id *id, int status);

#endif
