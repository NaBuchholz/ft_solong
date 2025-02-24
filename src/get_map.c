/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:36:32 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/17 14:40:29 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**load_map(int map_fd, t_game *game)
{
	char	*line;
	int		i;

	game->map = malloc(sizeof(char *) * (game->map_h + 1));
	line = get_next_line(map_fd);
	if (!game->map || !line)
	{
		if (!line)
			write(1, "Sem Linha\n", 11);
		return (NULL);
	}
	i = 0;
	while (line)
	{
		game->map[i] = line;
		i++;
		line = get_next_line(map_fd);
	}
	game->map[i] = NULL;
	if (game->map[0] == NULL)
		return (NULL);
	game->map_w = (int)ft_strlen(game->map[0]);
	return (game->map);
}
