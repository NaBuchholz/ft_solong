/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:45:00 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/19 15:27:47 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_env *envGame)
{
	int	new_x;
	int	new_y;

	new_x = envGame->game.player_x;
	new_y = envGame->game.player_y;

	// Mapeamento de teclas para movimento
	if (keycode == 65307) // Tecla ESC
	{
		close_game(envGame->game.map, -1);
		return (0);
	}
	else if (keycode == 13 || keycode == 126) // W ou seta para cima
		new_y--;
	else if (keycode == 1 || keycode == 125) // S ou seta para baixo
		new_y++;
	else if (keycode == 2 || keycode == 124) // D ou seta para direita
		new_x++;
	else if (keycode == 0 || keycode == 123) // A ou seta para esquerda
		new_x--;

	// Atualiza o mapa e renderiza novamente
	update_map(envGame, new_x, new_y);
	return (0);
}

int	mouse_handle(t_classMlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}
