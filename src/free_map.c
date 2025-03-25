/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:16:50 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/25 16:19:50 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_resource(void *mlx, void **resource)
{
	if (*resource)
	{
		mlx_destroy_image(mlx, *resource);
		*resource = NULL;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

void	free_sprites(t_classMlx *mlx)
{
	if (!mlx || !mlx->mlx)
		return ;
	free_resource(mlx->mlx, (void **)&mlx->wall);
	free_resource(mlx->mlx, (void **)&mlx->bg);
	free_resource(mlx->mlx, (void **)&mlx->char_still);
	free_resource(mlx->mlx, (void **)&mlx->collectables);
	free_resource(mlx->mlx, (void **)&mlx->exit);
}

static void	free_game_resources(t_env *envGame)
{
	if (!envGame)
		return ;
	free_sprites(&envGame->mlx);
	if (envGame->game.map)
	{
		free_map(envGame->game.map);
		envGame->game.map = NULL;
	}
	if (envGame->valid.map_cp)
	{
		free_map(envGame->valid.map_cp);
		envGame->valid.map_cp = NULL;
	}
	if (envGame->mlx.win && envGame->mlx.mlx)
	{
		mlx_destroy_window(envGame->mlx.mlx, envGame->mlx.win);
		envGame->mlx.win = NULL;
	}
	if (envGame->mlx.mlx)
	{
		mlx_destroy_display(envGame->mlx.mlx);
		free(envGame->mlx.mlx);
		envGame->mlx.mlx = NULL;
	}
}

void	close_game(t_env *envGame, int error_code)
{
	free_game_resources(envGame);
	if (error_code > -1)
		exit(error_handling(error_code));
	else
		exit(0);
}
