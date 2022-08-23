/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:28:34 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/22 11:46:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

//ERROR CODES:
# define INVALID_CHARACTERS_FOUND 		1
# define INVALID_NUMBER_OF_ARGUMENTS 	2
# define INVALID_NUMBER_OF_PHILOSOPHERS 3
# define INVALID_TIME_TO_DIE 			4
# define INVALID_TIME_TO_EAT 			5
# define INVALID_TIME_TO_SLEEP 			6
# define INVALID_NUMBER_TIMES_EAT 		7
# define FORK_ERROR						8

void	print_error(int error_key);

#endif
