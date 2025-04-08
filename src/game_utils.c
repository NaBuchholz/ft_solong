/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:05:29 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/08 18:13:09 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	initialize_sprites(t_classMlx *mlx, int *px)
{
	char	*bg;
	char	*char_still;
	char	*collectables;
	char	*exit;
	char	*wall;

	bg = "./assets/bg.xpm";
	char_still = "./assets/player_still.xpm";
	collectables = "./assets/collectible.xpm";
	exit = "./assets/exit.xpm";
	wall = "./assets/wall.xpm";
	mlx->bg = mlx_xpm_file_to_image(mlx->mlx, bg, px, px);
	mlx->char_still = mlx_xpm_file_to_image(mlx->mlx, char_still, px, px);
	mlx->collectables = mlx_xpm_file_to_image(mlx->mlx, collectables, px, px);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, exit, px, px);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, wall, px, px);
}

static void	put_image(t_classMlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x * 32, y * 32);
}

void	put_map(t_game *game, t_classMlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			if (game->map[y][x] == '0')
				put_image(mlx, mlx->bg, x, y);
			else if (game->map[y][x] == '1')
				put_image(mlx, mlx->wall, x, y);
			else if (game->map[y][x] == 'P')
				put_image(mlx, mlx->char_still, x, y);
			else if (game->map[y][x] == 'E')
				put_image(mlx, mlx->exit, x, y);
			else if (game->map[y][x] == 'C')
				put_image(mlx, mlx->collectables, x, y);
			x++;
		}
		y++;
	}
}

void	open_screen(t_env *envgame)
{
	int			win_w;
	int			win_h;
	int			px;

	envgame->mlx.mlx = mlx_init();
	if (envgame->mlx.mlx == NULL)
		close_game(envgame, 0, "The mlx pointer is NULL");
	win_w = envgame->game.map_w * 32;
	win_h = envgame->game.map_h * 32;
	if (win_h < 1 || win_w < 1)
		close_game(envgame, 0, "Windown dimension cannot be < 1");
	envgame->mlx.win = mlx_new_window(envgame->mlx.mlx, win_w, win_h, "SoLong");
	if (!envgame->mlx.win)
		close_game(envgame, 0, "No mlx windown found");
	initialize_sprites(&envgame->mlx, &px);
	put_map(&envgame->game, &envgame->mlx);
	mlx_key_hook(envgame->mlx.win, handle_key, envgame);
	mlx_hook(envgame->mlx.win, 17, 0, mouse_handle, envgame);
	mlx_loop(envgame->mlx.mlx);
}
