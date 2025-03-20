/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:55:48 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/20 14:38:07 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (lines == 0)
	{
		ft_printf("No lines found in the file.\n");
		return (-1);
	}
	close(file);
	return (lines);
}

static	int	is_valid_char(char c, t_valid_check *check)
{
	if (c == 'P')
		check->qnt_player++;
	if (c == 'E')
		check->qnt_exit++;
	if (c == 'C')
		check->qnt_collectables++;
	return (ft_strchr("EPC10", c) != NULL);
}

int	verify_elements(t_valid_check *check)
{
	if (check->qnt_collectables == 0)
		return (7);
	if (check->qnt_exit == 0)
		return (3);
	if (check->qnt_player == 0 || check->qnt_player > 1)
		return (13);
	return (0);
}

int	valid_chars(t_game *game, t_valid_check *check)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w - 1)
		{
			if (!is_valid_char(game->map[y][x], check))
				return (1);
			if (game->map[y][x] == 'P' && check->qnt_player == 1)
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
	return (verify_elements(check));
}

int	flood_fill(t_game *game, int x, int y, char **visited)
{
	if (x < 0 || x >= game->map_w || y < 0 || y >= game->map_h)
		return (1);
	if (game->map[y][x] == 'E')
		return (1);
	if (flood_fill(game, x + 1, y, visited)
		|| flood_fill(game, x - 1, y, visited)
		|| flood_fill(game, x, y + 1, visited)
		|| flood_fill(game, x, y - 1, visited))
		return (1);
	return (0);
}
