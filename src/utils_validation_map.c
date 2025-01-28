/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:55:48 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/01/28 16:47:14 by nbuchhol         ###   ########.fr       */
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

int	is_rectangle(char **map, size_t map_w, size_t map_h)
{
	size_t	x;

	x = 1;
	while (x < map_h)
	{
		if (ft_strlen(map[x]) != map_w)
			exit(error_handling(1));
		x++;
	}
	return (0);
}

int	valid_chars(char **map, size_t map_h, size_t map_w)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map_h)
	{
		x = 0;
		while (x < map_w)
		{
			if (!ft_strchr("EPC10", map[y][x]))
				exit(error_handling(1));
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
