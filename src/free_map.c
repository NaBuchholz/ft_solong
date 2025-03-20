/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:16:50 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/20 11:46:32 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		map = NULL;
	}
}
void	free_game_resources(t_env *env)
{
	if (env->mlx.win)
	{
		mlx_destroy_window(env->mlx.mlx, env->mlx.win);
		env->mlx.win = NULL;
	}
	if (env->game.map)
		free_map(env->game.map);
	if (env->mlx.mlx)
	{
		free(env->mlx.mlx);
		env->mlx.mlx = NULL;
	}
}
