/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:05:29 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/18 15:00:23 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_screen(t_game *game)
{
	t_classMlx	mlx_class;
	int			win_w;
	int			win_h;

	mlx_class.mlx = mlx_init();
	if (mlx_class.mlx == NULL)
		exit(error_handling(0));
	win_w = game->map_w * 32;
	win_h = game->map_h * 32;
	if (win_h < 1 || win_w < 1)
		exit(error_handling(5));
	mlx_class.win = mlx_new_window(mlx_class.mlx, win_w, win_h, "Hello world!");
	initialize_sprites(&mlx_class);
	put_map(&game, &mlx_class);
	mlx_loop(mlx_class.mlx);
}

void	initialize_sprites(t_classMlx *mlx)
{
	mlx->bg = mlx_xpm_file_to_image(mlx->mlx, "../assets/bg.xpm", 32, 32);
	mlx->char_still = mlx_xpm_file_to_image(mlx->mlx, "../assets/char_still.xpm", 32, 32);
	mlx->collectable = (mlx->mlx, "../assets/collectable.xpm", 32, 32);
	mlx->exit = (mlx->mlx, "../assets/exit.xpm", 32, 32);
	mlx->wall = (mlx->mlx, "../assets/bg.xpm", 32, 32);
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
			else if (game->map[y][x] == '0')
				put_image(mlx, mlx->bg, x, y);
			else if (game->map[y][x] == 'P')
				put_image(mlx, mlx->char_still, x, y);
			else if (game->map[y][x] == 'E')
				put_image(mlx, mlx->exit, x, y);
			else if (game->map[y][x] == 'C')
				put_image(mlx, mlx->collectable, x, y);
			x++;
		}
		y++;
	}
}


void	close_game(int fd, char **map, int error_code)
{
	close(fd);
	if (map)
		free_map(map);
	if (error_code > -1)
		exit(error_handling(error_code));
}

