/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:45:00 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/20 14:21:46 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_env *envGame)
{
	int	new_x;
	int	new_y;

	new_x = envGame->game.player_x;
	new_y = envGame->game.player_y;

	ft_printf("Posição X antiga: %d\n",new_x);
	ft_printf("Posição Y antiga: %d\n",new_y);
	// Mapeamento de teclas para movimento
	if (keycode == 65307) // Tecla ESC
	{
		close_game(envGame->game.map, -1);
		return (0);
	}
	else if (keycode == 119 || keycode == 65362) // W ou seta para cima
	{
		ft_printf("W ou seta para cima apertada\n");
		new_y--;
		update_map(envGame, new_x, new_y);
	}
	else if (keycode == 115 || keycode == 65364) // S ou seta para baixo
	{
		ft_printf("S ou seta para baixo apertada\n");
		new_y++;
		update_map(envGame, new_x, new_y);
	}
	else if (keycode == 100 || keycode == 65363) // D ou seta para direita
	{
		ft_printf("D ou seta para direita apertada\n");
		new_x++;
		update_map(envGame, new_x, new_y);
	}
	else if (keycode == 97 || keycode == 65361) // A ou seta para esquerda
	{
		ft_printf("A ou seta para esquerda apertada\n");
		new_x--;
		update_map(envGame, new_x, new_y);
	}
	ft_printf("---------------\nPosição X nova: %d\n",new_x);
	ft_printf("Posição Y nova: %d\n---------------\n",new_y);
	ft_printf("Tecla pressionada: %d\n", keycode);
	ft_printf("Nova posição calculada: X:%d, Y:%d\n", new_x, new_y);
	return (0);
}

int	mouse_handle(t_classMlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}
