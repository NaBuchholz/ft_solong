/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:36:32 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/08 12:47:19 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_map_empty(char **map)
{
	if (map[0] == NULL)
	{
		ft_printf("No Line: the map is empty!!\n");
		return (1);
	}
	return (0);
}

static int	exceeds_expected_lines(int current_line, int expected_lines)
{
	if (current_line > expected_lines)
	{
		ft_printf("Map height mismatch\n");
		return (1);
	}
	return (0);
}

static int	allocate_map_memory(t_env *envgame)
{
	envgame->game.map = malloc(sizeof(char *) * (envgame->game.map_h + 1));
	if (!envgame->game.map)
	{
		ft_printf("Memory allocation failed for copy map\n");
		envgame->game.map = NULL;
		return (0);
	}
	return (1);
}

static void	find_player_position(t_env *envgame, char *line, int i)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'P')
		{
			envgame->game.player_x = j;
			envgame->game.player_y = i;
		}
		j++;
	}
}

char	**load_map(t_env *envgame)
{
	char	*line;
	int		i;

	if (envgame->fd < 0 || !allocate_map_memory(envgame))
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(envgame->fd);
		if (!line)
			break ;
		if (exceeds_expected_lines(i, envgame->game.map_h))
			return (free(line), NULL);
		envgame->game.map[i] = line;
		find_player_position(envgame, line, i++);
	}
	envgame->game.map[i] = NULL;
	if (is_map_empty(envgame->game.map))
		return (NULL);
	envgame->game.map_w = (int)ft_strlen(envgame->game.map[0]);
	if (envgame->game.map[0][envgame->game.map_w - 1] == '\n')
		envgame->game.map_w -= 1;
	return (envgame->game.map);
}
