# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 13:15:15 by rmazurit          #+#    #+#              #
#    Updated: 2022/08/22 13:28:25 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=			philo_bonus

CC 			= 		cc

FLAGS		= 		-Wall -Wextra -Werror

SRC 		= 		./main_bonus.c								\
      				./src/input_parser/args_checker_bonus.c		\
					./src/input_parser/input_parser_bonus.c		\
					./src/simulator/actions_bonus.c				\
					./src/simulator/semaphores_bonus.c			\
					./src/simulator/simulator_bonus.c			\
					./src/simulator/time_calculato_bonus.c		\
					./src/simulator/watcher_bonus.c				\
					./src/message_printer_bonus.c				\

TOOLS_SRC	=		./tools/ft_atol_bonus.c						\
					./tools/ft_check_invalid_chars_bonus.c		\
					./tools/ft_is_digit_bonus.c					\
					./tools/ft_usleep_bonus.c					\

OBJ 		= 		${SRC:.c=.o}
TOOLS_OBJ 	= 		${TOOLS_SRC:.c=.o}

$(NAME): $(OBJ) $(TOOLS_OBJ)
	${CC} ${FLAGS} ${OBJ} ${TOOLS_OBJ} -o ${NAME}

all: $(NAME)

clean:
	rm -f ${OBJ} ${TOOLS_OBJ} ${BONUS_OBJ}

fclean:
	rm -f ${OBJ} ${TOOLS_OBJ} ${BONUS_OBJ} ${NAME}

re: fclean all

.PHONY: all clean fclean re