/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:50:08 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/20 15:39:50 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_collectible(t_env *envGame, int new_x, int new_y)
{
	if (envGame->game.map[new_y][new_x] == 'C'
		&& envGame->valid.qnt_collectables > 0)
	{
		envGame->valid.qnt_collectables-= 1;
		ft_printf("Collectible picked up! Remaining: %d\n",
			envGame->valid.qnt_collectables);
	}
}

static int	can_exit(t_env *envGame, int new_x, int new_y)
{
	if (envGame->game.map[new_y][new_x] == 'E')
	{
		if (envGame->valid.qnt_collectables == 0)
		{
			ft_printf("You won the game!\n");
			close_game(envGame->game.map, 0);
		}
		else
		{
			ft_printf("You need to collect all collectibles before exiting!\n");
			return (0);
		}
	}
	return (1);
}

void	update_map(t_env *envGame, int new_x, int new_y)
{
	if (envGame->game.map[new_y][new_x] == '1')
		return ;
	if (!can_exit(envGame, new_x, new_y))
		return ;
	check_collectible(envGame, new_x, new_y);
	envGame->game.map[envGame->game.player_y][envGame->game.player_x] = '0';
	envGame->game.map[new_y][new_x] = 'P';
	envGame->game.player_x = new_x;
	envGame->game.player_y = new_y;
	envGame->game.moves += 1;
	ft_printf("Moves: %d\n", envGame->game.moves);
	put_map(&envGame->game, &envGame->mlx);
}
