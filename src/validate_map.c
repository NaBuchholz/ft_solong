/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:58:46 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/01/20 16:54:14 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static	void	initialize_valid_check(t_valid_check *valid_check)
// {
// 	valid_check->first_line_len = 0;
// 	valid_check->qnt_player = 0;
// 	valid_check->qnt_collectibles = 0;
// 	valid_check->qnt_exit = 0;
// }

int	count_lines(int file)
{
	char	*line;
	int		lines;

	line = get_next_line(file);
	lines = 0;
	while (line)
	{
		free(line);
		lines++;
		line = get_next_line(file);
	}
	return (lines);
}

static char	**load_map(int map_fd, t_game *game)
{
	char	*line;
	int		i;

	game->map = malloc(sizeof(char *) * (game->map_hight + 1));
	if (!game->map)
		return (NULL);
	line = get_next_line(map_fd);
	i = 0;
	while (line)
	{
		game->map[i] = line;
		free(line);
		i++;
		line = get_next_line(map_fd);
	}
	game->map[i] = NULL;
	if (game->map[0])
		game->map_width = ft_strlen(game->map[0]);
	else
		game->map_width = 0;
	return (game->map);
}

int	valid_map(char *map_file)
{
	int				map_fd;
	t_game			game;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		return (free_map(map_fd, NULL), 1);
	game.map_hight = count_lines(map_fd);
	game.map = load_map(map_fd, &game);
	if (!game.map)
		return (free_map(map_fd, NULL), 1);
	close(map_fd);
	return (0);
}

