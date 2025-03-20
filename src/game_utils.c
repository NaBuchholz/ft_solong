/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:05:29 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/20 14:36:40 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_sprites(t_classMlx *mlx)
{
	int		px;
	char	*bg;
	char	*char_still;
	char	*collectables;
	char	*exit;
	char	*wall;

	px = 32;
	bg = "./assets/bg.xpm";
	char_still = "./assets/player_still.xpm";
	collectables = "./assets/collectible.xpm";
	exit = "./assets/exit.xpm";
	wall = "./assets/bg.xpm";
	mlx->bg = mlx_xpm_file_to_image(mlx->mlx, bg, &px, &px);
	mlx->char_still = mlx_xpm_file_to_image(mlx->mlx, char_still, &px, &px);
	mlx->collectables = mlx_xpm_file_to_image(mlx->mlx, collectables, &px, &px);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, exit, &px, &px);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, wall, &px, &px);
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
				put_image(mlx, mlx->bg, x, y);
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

void	open_screen(t_env *envGame)
{
	int			win_w;
	int			win_h;

	envGame->mlx.mlx = mlx_init();
	if (envGame->mlx.mlx == NULL)
		exit(error_handling(0));
	win_w = envGame->game.map_w * 32;
	win_h = envGame->game.map_h * 32;
	if (win_h < 1 || win_w < 1)
		exit(error_handling(5));
	envGame->mlx.win = mlx_new_window(envGame->mlx.mlx, win_w, win_h, "SoLong");
	initialize_sprites(&envGame->mlx);
	put_map(&envGame->game, &envGame->mlx);
	ft_printf("Mapa redesenhado:\n");
	for (int y = 0; y < envGame->game.map_h; y++)
		ft_printf("%s\n", envGame->game.map[y]);
	mlx_key_hook(envGame->mlx.win, handle_key, envGame);
	mlx_hook(envGame->mlx.win, 17, 0, mouse_handle, &envGame->mlx);
	mlx_loop(envGame->mlx.mlx);
}

void	close_game(char **map, int error_code)
{
	if (map)
		free_map(map);
	if (error_code > -1)
		exit(error_handling(error_code));
}
