/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:45:00 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/08 12:47:19 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_env *envgame)
{
	int	new_x;
	int	new_y;

	new_x = envgame->game.player_x;
	new_y = envgame->game.player_y;
	if (keycode == 65307)
		return (close_game(envgame, -1), 0);
	else if (keycode == 119 || keycode == 65362)
		update_map(envgame, new_x, --new_y);
	else if (keycode == 115 || keycode == 65364)
		update_map(envgame, new_x, ++new_y);
	else if (keycode == 100 || keycode == 65363)
		update_map(envgame, ++new_x, new_y);
	else if (keycode == 97 || keycode == 65361)
		update_map(envgame, --new_x, new_y);
	return (0);
}

int	mouse_handle(t_env *envgame)
{
	if (envgame->mlx.mlx && envgame->mlx.win)
		close_game(envgame, 0);
	return (0);
}
