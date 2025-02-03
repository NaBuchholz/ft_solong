/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:55:48 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/03 13:41:49 by nbuchhol         ###   ########.fr       */
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

int	valid_chars(t_game game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game.map_h)
	{
		x = 0;
		while (x < game.map_w)
		{
			if (!ft_strchr("EPC10", game.map[y][x]))
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
