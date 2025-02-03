/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:15:22 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/03 13:42:05 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
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
}	t_valid_check;

typedef struct s_game
{
	char		**map;
	size_t		map_h;
	size_t		map_w;
}	t_game;

size_t	ft_strlen(const char *s);
int		count_lines(int file);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		is_rectangle(t_game game);
void	free_map(char **map, int error_code);
void	validate_file_name(char *name);
int		valid_chars(t_game game);
char	**load_map(int map_fd, t_game *game);
int		error_handling(int error_code);
int		valid_map(char *map);

#endif // SO_LONG

