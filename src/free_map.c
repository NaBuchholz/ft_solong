/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:16:50 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/20 16:20:18 by nbuchhol         ###   ########.fr       */
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

void	free_sprites(t_classMlx *mlx)
{
	if (mlx->wall)
	{
		mlx_destroy_image(mlx->mlx, mlx->wall);
		mlx->wall = NULL;
	}
	if (mlx->bg)
	{
		mlx_destroy_image(mlx->mlx, mlx->bg);
		mlx->bg = NULL;
	}
	if (mlx->char_still)
	{
		mlx_destroy_image(mlx->mlx, mlx->char_still);
		mlx->char_still = NULL;
	}
	if (mlx->collectables)
	{
		mlx_destroy_image(mlx->mlx, mlx->collectables);
		mlx->collectables = NULL;
	}
	if (mlx->exit)
	{
		mlx_destroy_image(mlx->mlx, mlx->exit);
		mlx->exit = NULL;
	}
}

 static void	free_game_resources(t_env *envGame)
{
	free_sprites(&envGame->mlx);
	if (envGame->game.map)
		free_map(envGame->game.map);
	if (envGame->valid.visited_map)
		free_map(envGame->valid.visited_map);
	if (envGame->mlx.win)
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
