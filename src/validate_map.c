/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:58:46 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/08 22:48:40 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_surrounded_by_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_w)
	{
		if (game->map[0][x] != '1' || game->map[game->map_h - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < game->map_h)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_w - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	is_rectangle(t_game game)
{
	int	x;
	int	expected_width;

	expected_width = game.map_w;
	x = 0;
	while (x < game.map_h)
	{
		if ((int)ft_strlen(game.map[x]) - 1 != expected_width)
			return (1);
		x++;
	}
	return (0);
}

static int	is_map_too_large(t_env *envgame)
{
	int	max_width;
	int	max_height;
	int	map_pixel_width;
	int	map_pixel_height;

	max_width = 1366;
	max_height = 768;
	map_pixel_width = envgame->game.map_w * 32;
	map_pixel_height = envgame->game.map_h * 32;
	if (map_pixel_width > max_width - 100
		|| map_pixel_height > max_height - 100)
		return (1);
	return (0);
}

void	valid_map(t_env *envgame)
{
	if (!envgame->game.map)
		close_game(envgame, 2, "No game map found");
	if (is_rectangle(envgame->game))
		close_game(envgame, 2, "Not a rectangle");
	if (!is_surrounded_by_walls(&envgame->game))
		close_game(envgame, 7, "The map isen't surrounded by walls");
	if (valid_chars(&envgame->game, &envgame->valid))
		close_game(envgame, 5, "The map has invalid chars");
	if (!flood_fill(envgame, envgame->game.player_x, envgame->game.player_y))
		close_game(envgame, 9, "No valid path found");
	if (is_map_too_large(envgame))
		close_game(envgame, 4, "The map is too large");
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
