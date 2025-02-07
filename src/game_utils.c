/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:05:29 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/07 13:53:22 by nbuchhol         ###   ########.fr       */
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
	mlx_class.win = mlx_new_window(mlx_class.mlx, win_w, win_h, "Hello world!");
	mlx_loop(mlx_class.mlx);
}

void	close_game(int fd, char **map, int error_code)
{
	close(fd);
	if (map)
		free_map(map);
	if (error_code > -1)
		exit(error_handling(error_code));
}

void	close_mlx(void *mlx)
{

}
