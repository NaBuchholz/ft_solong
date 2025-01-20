# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 12:09:52 by nbuchhol          #+#    #+#              #
#    Updated: 2025/01/20 16:57:11 by nbuchhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
SRC = src/error_handling.c \
	  src/get_next_line/get_next_line_utils.c \
	  src/get_next_line/get_next_line.c \
	  src/free_map.c \
	  src/validate_map.c \
	  src/so_long.c
OBJ = ${SRC:.c=.o}
SUB_DIRS = libft minilibx
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${OBJ} -o ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $^ -o $@

clean:
	${RM} ${OBJ}
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY = all clean fclean re
