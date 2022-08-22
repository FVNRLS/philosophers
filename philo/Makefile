# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 13:15:15 by rmazurit          #+#    #+#              #
#    Updated: 2022/08/22 19:44:43 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		philo

CC 			= 		cc

FLAGS		= 		-Wall -Wextra -Werror

SRC 		= 		./main.c									\
					./src/input_parser/args_checker.c			\
					./src/input_parser/input_parser.c			\
					./src/simulator/actions.c					\
					./src/simulator/mutex_controller.c			\
					./src/simulator/simulator.c					\
					./src/simulator/time_calculator.c			\
					./src/simulator/watcher.c					\
					./src/message_printer.c						\

TOOLS_SRC	=		./tools/ft_atol.c							\
					./tools/ft_check_invalid_chars.c			\
					./tools/ft_is_digit.c						\
					./tools/ft_usleep.c							\
					./tools/ft_free_phils.c						\

OBJ 		= 		${SRC:.c=.o}
TOOLS_OBJ 	= 		${TOOLS_SRC:.c=.o}

$(NAME): $(OBJ) $(TOOLS_OBJ)
	${CC} ${FLAGS} ${OBJ} ${TOOLS_OBJ} -o ${NAME}

all: $(NAME)

clean:
	rm -f ${OBJ} ${TOOLS_OBJ}

fclean:
	rm -f ${OBJ} ${TOOLS_OBJ} ${NAME}

re: fclean all

.PHONY: all clean fclean re