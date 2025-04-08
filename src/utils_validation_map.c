/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:55:48 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/07 21:54:01 by nbuchhol         ###   ########.fr       */
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

int	flood_fill(t_env *env, int x, int y)
{
	static int	copy_collectbles;
	static int	exit_found;

	if (!copy_collectbles)
		copy_collectbles = env->valid.qnt_collectables + 1;
	if (x < 0 || x >= env->game.map_w || y < 0 || y >= env->game.map_h)
		return (0);
	if (env->valid.map_cp[y][x] == '1' || env->valid.map_cp[y][x] == 'V')
		return (0);
	if (env->valid.map_cp[y][x] == 'C')
		copy_collectbles--;
	if (env->valid.map_cp[y][x] == 'E')
	{
		exit_found = 1;
		return (env->valid.map_cp[y][x] = 'V', 0);
	}
	if (copy_collectbles == 1 && exit_found == 1)
		return (1);
	env->valid.map_cp[y][x] = 'V';
	if (flood_fill(env, x + 1, y)
		|| flood_fill(env, x - 1, y)
		|| flood_fill(env, x, y + 1)
		|| flood_fill(env, x, y - 1))
		return (1);
	return (0);
}
