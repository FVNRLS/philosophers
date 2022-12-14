/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:15:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/23 16:07:09 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_BONUS_H
# define ACTIONS_BONUS_H

# include "structs_bonus.h"

//STATES
# define FORK_TAKEN				1
# define IS_EATING				2
# define IS_SLEEPING			3
# define IS_THINKING			4
# define FREE					5
# define PHIL_SATED				6
# define PHIL_DIED				7

//PHILOSOPHERS ACTIONS
void	take_forks(t_phil *phil);
void	eat(t_phil *phil);
void	ph_sleep(t_phil *phil);
void	think(t_phil *phil);
void	print_status(t_phil *phil, int status);

#endif
