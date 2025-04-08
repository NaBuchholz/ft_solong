/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:45:00 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/08 11:54:08 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_env *envGame)
{
	int	new_x;
	int	new_y;

	new_x = envGame->game.player_x;
	new_y = envGame->game.player_y;
	if (keycode == 65307)
		return (close_game(envGame, -1), 0);
	else if (keycode == 119 || keycode == 65362)
		update_map(envGame, new_x, --new_y);
	else if (keycode == 115 || keycode == 65364)
		update_map(envGame, new_x, ++new_y);
	else if (keycode == 100 || keycode == 65363)
		update_map(envGame, ++new_x, new_y);
	else if (keycode == 97 || keycode == 65361)
		update_map(envGame, --new_x, new_y);
	return (0);
}

int	mouse_handle(t_env *envGame)
{
	if (envGame->mlx.mlx && envGame->mlx.win)
		close_game(envGame, 0);
	return (0);
}
