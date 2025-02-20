/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:15:22 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/20 01:29:51 by nbuchhol         ###   ########.fr       */
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
	size_t	qnt_collectibles;
	size_t	qnt_exit;
	char	**visited_map;
}	t_valid_check;

typedef struct s_classMlx
{
	void	*mlx;
	void	*win;
	int	*wall;
	void	*bg;
	void	*char_up;
	void	*char_still;
	void	*char_left;
	void	*char_right;
	void	*collectable;
	void	*exit;
}	t_classMlx;

typedef struct s_game
{
	char		**map;
	int			map_h;
	int			map_w;
	size_t		player_x;
	size_t		player_y;
}	t_game;

int		count_lines(int file);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(const char *prefix, const char *suffix);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	close_game(int fd, char **map, int error_code);
int		is_rectangle(t_game game);
void	free_map(char **map);
void	validate_file_name(char *name);
int		verify_elements(t_valid_check *check);
int		valid_chars(t_game game, t_valid_check *check);
char	**load_map(int map_fd, t_game *game);
int		error_handling(int error_code);
int		valid_map(char *map, t_game *game);
void	open_screen(t_game *game);
int		key_handle(int keycode);
int		mouse_handle(t_classMlx *mlx);

#endif // SO_LONG

