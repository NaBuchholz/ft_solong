/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:50:08 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/08 12:47:19 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_collectible(t_env *envgame, int new_x, int new_y)
{
	if (envgame->game.map[new_y][new_x] == 'C'
		&& envgame->valid.qnt_collectables > 0)
	{
		envgame->valid.qnt_collectables -= 1;
		ft_printf("Collectible picked up! Remaining: %d\n",
			envgame->valid.qnt_collectables);
	}
}

static int	can_exit(t_env *envgame, int new_x, int new_y)
{
	if (envgame->game.map[new_y][new_x] == 'E')
	{
		if (envgame->valid.qnt_collectables == 0)
		{
			ft_printf("You won the game!\n");
			close_game(envgame, -1);
		}
		else
		{
			ft_printf("You need to collect all collectibles before exiting!\n");
			return (0);
		}
	}
	return (1);
}

void	update_map(t_env *envgame, int new_x, int new_y)
{
	if (envgame->game.map[new_y][new_x] == '1')
		return ;
	if (!can_exit(envgame, new_x, new_y))
		return ;
	check_collectible(envgame, new_x, new_y);
	envgame->game.map[envgame->game.player_y][envgame->game.player_x] = '0';
	envgame->game.map[new_y][new_x] = 'P';
	envgame->game.player_x = new_x;
	envgame->game.player_y = new_y;
	envgame->game.moves += 1;
	ft_printf("Moves: %d\n", envgame->game.moves);
	put_map(&envgame->game, &envgame->mlx);
}

void	move_player(t_env *envgame, int new_x, int new_y)
{
	if (new_x >= 0 && new_x < envgame->game.map_w
		&& new_y >= 0 && new_y < envgame->game.map_h)
		update_map(envgame, new_x, new_y);
}
