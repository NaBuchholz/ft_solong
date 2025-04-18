/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_copy.c                                         :+:      :+:    :+:   */
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
		ft_printf("No Line: the map copy is empty!!\n");
		return (1);
	}
	return (0);
}

static int	allocate_map_memory(t_env *envgame)
{
	envgame->valid.map_cp = malloc(sizeof(char *) * (envgame->game.map_h + 1));
	if (!envgame->valid.map_cp)
		return (0);
	return (1);
}

void	load_copy(t_env *envgame)
{
	char	*line;
	int		i;

	if (!allocate_map_memory(envgame))
		return ;
	i = 0;
	while (i < envgame->game.map_h)
	{
		line = ft_strdup(envgame->game.map[i]);
		if (!line)
			break ;
		envgame->valid.map_cp[i++] = line;
	}
	envgame->valid.map_cp[i] = NULL;
	if (is_map_empty(envgame->valid.map_cp))
		return ;
}
