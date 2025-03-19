/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:36:32 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/19 13:53:08 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_map_empty(char **map)
{
	if (map[0] == NULL)
	{
		write(1, "No Line: the map is empty!!\n", 8);
		return (1);
	}
	return (0);
}

static int	exceeds_expected_lines(int current_line, int expected_lines)
{
	if (current_line > expected_lines)
	{
		write(1, "Map height mismatch\n", 21);
		return (1);
	}
	return (0);
}

char	**load_map(t_env *envGame)
{
	char	*line;
	int		i;

	if (envGame->fd < 0)
		return (NULL);
	envGame->game.map = malloc(sizeof(char *) * (envGame->game.map_h + 1));
	if (!envGame->game.map)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(envGame->fd);
		if (!line)
			break ;
		if (exceeds_expected_lines(i, envGame->game.map_h))
			return (free(line), NULL);
		envGame->game.map[i++] = line;
	}
	envGame->game.map[i] = NULL;
	if (is_map_empty(envGame->game.map))
		return (NULL);
	envGame->game.map_w = (int)ft_strlen(envGame->game.map[0]);
	if (envGame->game.map[0][envGame->game.map_w - 1] == '\n')
		envGame->game.map_w -= 1;
	return (envGame->game.map);
}
