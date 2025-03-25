/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:36:32 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/25 16:56:12 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_map_empty(char **map)
{
	if (map[0] == NULL)
	{
		ft_printf("No Line: the map copy is empty!!\n");
		return (1);
	}
	return (0);
}

static int	allocate_map_memory(t_env *envGame)
{
	envGame->valid.map_cp = malloc(sizeof(char *) * (envGame->game.map_h + 1));
	if (!envGame->valid.map_cp)
		return (0);
	return (1);
}

void	load_copy(t_env *envGame)
{
	char	*line;
	int		i;

	if (!allocate_map_memory(envGame))
	{
		ft_printf("erro alocação na cópia");
		return ;
	}
	i = 0;
	while (1)
	{
		line = ft_strdup(envGame->game.map[i]);
		if (!line)
			break ;
		envGame->valid.map_cp[i++] = line;
		free(line);
	}
	envGame->valid.map_cp[i] = NULL;
	if (is_map_empty(envGame->valid.map_cp))
		return ;
}
