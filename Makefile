# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 12:09:52 by nbuchhol          #+#    #+#              #
#    Updated: 2025/01/28 16:50:46 by nbuchhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -I./minilibx
SRC = src/error_handling.c \
	  src/utils_validation_map.c \
	  src/get_map.c \
	  src/get_next_line/get_next_line_utils.c \
	  src/get_next_line/get_next_line.c \
	  src/free_map.c \
	  src/validate_map.c \
	  src/so_long.c
OBJ = ${SRC:.c=.o}
SUB_DIRS = libft minilibx
LIBS = libft/libft.a minilibx/libmlx.a
RM = rm -f

all: init-submodules ${NAME}

${NAME}: ${OBJ} ${LIBS}
	@${CC} ${OBJ} ${LIBS} -o ${NAME}

libft/libft.a:
	@$(MAKE) -C libft

minilibx/libmlx.a:
	@$(MAKE) -C minilibx

%.o: %.c
	@${CC} ${CFLAGS} -c $^ -o $@

init-submodules:
	@if [ ! -d "libft" ] || [ ! -f "libft/.git" ]; then \
		echo "Inicializando submódulo libft..."; \
		git submodule update --init --recursive libft; \
	else \
		echo "Submódulo libft já está inicializado."; \
	fi
	@if [ ! -d "minilibx" ] || [ ! -f "minilibx/.git" ]; then \
		echo "Inicializando submódulo minilibx..."; \
		git submodule update --init --recursive minilibx; \
	else \
		echo "Submódulo minilibx já está inicializado."; \
	fi

clean:
	${RM} ${OBJ}
	@for dir in $(SUB_DIRS); do $(MAKE) -C $$dir clean; done

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re init-submodules
