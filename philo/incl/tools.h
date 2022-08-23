/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:03:27 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/19 14:56:12 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "structs.h"

long	ft_atol(const char *str);
bool	ft_check_invalid_chars(char *str);
bool	ft_is_digit(char c);
void	ft_usleep(t_phil *phil, long ms);
void	ft_free_phils(t_phil *phil);

#endif
