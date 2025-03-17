/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:45:00 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/17 13:51:38 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65307)
	{
		close_game(game->map, -1);
		return (0);
	}
	else if (keycode == 13 || keycode == 126)
		new_x--;
	else if (keycode == 1 | keycode == 125)
		new_x++;
	else if (keycode == 2 || keycode == 124)
		new_y--;
	else if (keycode == 0 || keycode == 123)
		new_y++;
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("Now position: (%d, %d)\n", game->player_x, game->player_y);
	return (0);
}

int	mouse_handle(t_classMlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}
