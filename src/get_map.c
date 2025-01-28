/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:36:32 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/01/28 15:43:38 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**load_map(int map_fd, t_game *game)
{
	char	*line;
	int		i;

	game->map = malloc(sizeof(char *) * (game->map_height + 1));
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
