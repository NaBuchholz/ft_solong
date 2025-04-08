/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:16:50 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/08 12:47:19 by nbuchhol         ###   ########.fr       */
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
	free(map);
}

static void	free_sprites(t_classMlx *mlx)
{
	if (!mlx || !mlx->mlx)
		return ;
	free_resource(mlx->mlx, (void **)&mlx->wall);
	free_resource(mlx->mlx, (void **)&mlx->bg);
	free_resource(mlx->mlx, (void **)&mlx->char_still);
	free_resource(mlx->mlx, (void **)&mlx->collectables);
	free_resource(mlx->mlx, (void **)&mlx->exit);
}

static void	free_game_resources(t_env *envgame)
{
	if (!envgame)
		return ;
	free_sprites(&envgame->mlx);
	if (envgame->game.map)
	{
		free_map(envgame->game.map);
		envgame->game.map = NULL;
	}
	if (envgame->valid.map_cp)
	{
		free_map(envgame->valid.map_cp);
		envgame->valid.map_cp = NULL;
	}
	if (envgame->mlx.mlx)
	{
		mlx_destroy_display(envgame->mlx.mlx);
		free(envgame->mlx.mlx);
		envgame->mlx.mlx = NULL;
	}
}

void	close_game(t_env *envgame, int error_code)
{
	free_game_resources(envgame);
	if (error_code > -1)
		exit(1);
	else
		exit(0);
}
