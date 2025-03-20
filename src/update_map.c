/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:50:08 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/20 12:57:57 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_map(t_env *envGame, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= envGame->game.map_w || new_y < 0
		|| new_y >= envGame->game.map_h)
		return ;
	if (envGame->game.map[new_y][new_x] != '1')
	{
		ft_printf("Atualizando mapa para nova posição: X:%d, Y:%d\n", new_x, new_y);
		ft_printf("Mapa antes da atualização:\n");
		for (int y = 0; y < envGame->game.map_h; y++)
			ft_printf("%s\n", envGame->game.map[y]);

		envGame->game.map[envGame->game.player_y][envGame->game.player_x] = '0';
		envGame->game.map[new_y][new_x] = 'P';
		envGame->game.player_x = new_x;
		envGame->game.player_y = new_y;
		ft_printf("player new y: %d\n", envGame->game.player_y);
		ft_printf("player new x: %d\n", envGame->game.player_x);
		envGame->game.moves += 1;
		ft_printf("Moves: %d\n", envGame->game.moves);
		ft_printf("Player position: X:%d, Y:%d\n", envGame->game.player_x, envGame->game.player_y);

		// Redesenha o mapa após o movimento
		put_map(&envGame->game, &envGame->mlx);
	}
}
