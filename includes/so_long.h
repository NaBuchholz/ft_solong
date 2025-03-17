/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:15:22 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/17 14:08:15 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif // END BUFFER_SIZE

typedef struct s_valid_check
{
	size_t	first_line_len;
	size_t	qnt_player;
	size_t	qnt_collectables;
	size_t	qnt_exit;
	char	**visited_map;
}	t_valid_check;

typedef struct s_classMlx
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*bg;
	void	*char_still;
	void	*collectables;
	void	*exit;
}	t_classMlx;

typedef struct s_game
{
	char		**map;
	int			map_h;
	int			map_w;
	size_t		player_x;
	size_t		player_y;
	int			moves;
}	t_game;

typedef struct s_env
{
	t_game			game;
	t_classMlx		mlx;
	t_valid_check	valid;
	int				fd;
}	t_env;


int		count_lines(int file);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(const char *prefix, const char *suffix);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	close_game(char **map, int error_code);
int		is_rectangle(t_game game);
void	free_map(char **map);
int		validate_file_name(char *name);
int		verify_elements(t_valid_check *check);
int		valid_chars(t_game game, t_valid_check *check);
char	**load_map(int map_fd, t_game *game);
int		error_handling(int error_code);
void	valid_map(char *map_file, t_env *envGame);
void	open_screen(t_game *game);
int		handle_key(int keycode, t_game *game);
int		mouse_handle(t_classMlx *mlx);

#endif // SO_LONG

