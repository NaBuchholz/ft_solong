/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:55:48 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/05 12:53:23 by nbuchhol         ###   ########.fr       */
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
	return (lines);
}

static	int	is_valid_char(char c)
{
	return (ft_strchr("EPC10", c) != NULL);
}

int	valid_chars(t_game game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game.map_h)
	{
		x = 0;
		while (x < game.map_w - 1)
		{
			if (!is_valid_char(game.map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// int	element_blocked(char **map, size_t map_w, size_t map_h)
// {
// 	return (0);
// }

// int is_all_wall()
// {
// 	//comprimento -2 => linhas do meio => checar primeira e última posição do x
// }
