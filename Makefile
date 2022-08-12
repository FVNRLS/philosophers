# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 13:15:15 by rmazurit          #+#    #+#              #
#    Updated: 2022/08/11 11:53:54 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		philo
BONUS_NAME	=		philo_bonus

CC 			= 		cc

FLAGS		= 		-Wall -Wextra -Werror

SRC 		= 		./src/philo/main.c										\

BONUS_SRC	= 		./src/philo_bonus/main.c								\

TOOLS_SRC	=		./src/tools/ft_strlen.c									\

OBJ 		= 		${SRC:.c=.o}
BONUS_OBJ	=		${BONUS_SRC:.c=.o}
TOOLS_OBJ 	= 		${TOOLS_SRC:.c=.o}

$(NAME): $(OBJ) $(TOOLS_OBJ)
	${CC} ${FLAGS} ${OBJ} ${TOOLS_OBJ} -o ${NAME}

all: $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(TOOLS_OBJ)
	${CC} ${FLAGS} ${BONUS_OBJ} ${TOOLS_OBJ} -o ${BONUS_NAME}

bonus: $(BONUS_NAME)

clean:
	rm -f ${OBJ} ${TOOLS_OBJ} ${BONUS_OBJ}

fclean:
	rm -f ${OBJ} ${TOOLS_OBJ} ${BONUS_OBJ} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus