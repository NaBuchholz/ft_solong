/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:58:46 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/17 15:36:39 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_map(char *map_file, t_game *game)
{
	int				map_fd;
	t_valid_check	check;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		close_game(map_fd, NULL, 5);
	game->map_h = count_lines(map_fd);
	close_game(map_fd, NULL, -1);
	map_fd = open(map_file, O_RDONLY);
	game->map = load_map(map_fd, game);
	if (!game->map)
		close_game(map_fd, game->map, 2);
	if (is_rectangle(*game))
		close_game(map_fd, game->map, 2);
	if (valid_chars(*game, &check))
		close_game(map_fd, game->map, valid_chars(*game, &check));
	return (0);
}

int	validate_file_name(char *name)
{
	size_t	name_len;
	size_t	ext_len;
	size_t	comparation;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(".ber");
	comparation = ft_strncmp(name + name_len - ext_len, ".ber", ext_len);
	if (name_len <= ext_len || comparation != 0)
		return (0);
	return (1);
}

int	is_rectangle(t_game game)
{
	int	x;

	if (game.map_h == game.map_w)
		return (1);
	x = 0;
	while (x < game.map_h)
	{
		if ((int)ft_strlen(game.map[x]) != game.map_w)
			return (1);
		x++;
	}
	return (0);
}
