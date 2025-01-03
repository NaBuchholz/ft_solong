# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 12:09:52 by nbuchhol          #+#    #+#              #
#    Updated: 2025/01/03 12:12:09 by nbuchhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =
OBJ = ${SRC:.c=.o}
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.c
	@${CC} ${CFLAGS} -c $^ -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY = all clean fclean re
