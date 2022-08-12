/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:03:27 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 17:17:36 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdbool.h>

long	ft_atol(const char *str);
void	ft_check_invalid_chars(char *str);
bool	ft_is_digit(char c);
int		ft_strlen(const char *s);


#endif
