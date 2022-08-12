/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:28:34 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 19:29:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//ERROR CODES:
# define INVALID_CHARACTERS_FOUND 		1
# define INVALID_NUMBER_OF_ARGUMENTS 	2
# define INVALID_NUMBER_OF_PHILOSOPHERS 3
# define INVALID_TIME_TO_DIE 			4
# define INVALID_TIME_TO_EAT 			5


void	print_error_exit(int error_key);

#endif
