# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 12:09:52 by nbuchhol          #+#    #+#              #
#    Updated: 2025/04/09 10:11:09 by nbuchhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -I./minilibx
DEBUG_FLAGS = -g
MLX_FLAGS = -Lminilibx -lmlx -lX11 -lXext -lm
SRC = src/error_handling.c \
	  src/utils_validation_map.c \
	  src/game_utils.c \
	  src/get_map.c \
	  src/get_copy.c \
	  src/update_map.c \
	  src/get_next_line/get_next_line_utils.c \
	  src/get_next_line/get_next_line.c \
	  src/free_map.c \
	  src/validate_map.c \
	  src/player.c \
	  src/so_long.c
OBJ = ${SRC:.c=.o}
SUB_DIRS = libft minilibx
LIBS = libft/libft.a minilibx/libmlx.a
RM = rm -f

all: init-submodules ${NAME}

${NAME}: ${OBJ} ${LIBS}
	@${CC} ${OBJ} ${LIBS} libft/printf/libftprintf.a ${MLX_FLAGS} -o ${NAME}

libft/libft.a:
	@$(MAKE) -C libft

minilibx/libmlx.a:
	@$(MAKE) -C minilibx > /dev/null 2>/dev/null

%.o: %.c
	@${CC} ${CFLAGS} ${DEBUG_FLAGS} -c $^ -o $@

init-submodules:
	@for submodule in $(SUB_DIRS); do \
		if [ ! -d "$$submodule" ] || [ ! -f "$$submodule/.git" ]; then \
			echo "Initializing $$submodule submodule..."; \
			git submodule update --init --recursive $$submodule; \
		else \
			echo "Updating $$submodule submodule..."; \
			BRANCH=$$(git config -f .gitmodules --get submodule.$$submodule.branch || echo "master"); \
			cd $$submodule && git checkout $$BRANCH && git pull origin $$BRANCH && cd ..; \
		fi; \
	done

clean:
	${RM} ${OBJ}
	@for dir in $(SUB_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C libft fclean

debug: ${NAME}
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./${NAME} ./maps/control.ber

gdb: ${NAME}
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --vgdb-error=0 ./${NAME}

re: fclean all

.PHONY: all clean fclean re init-submodules debug gdb
