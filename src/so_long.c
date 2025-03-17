/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:12:47 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/13 17:09:02 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_counters(t_env *envGame)
{
	envGame->game.map_h = 0;
	envGame->game.map_w = 0;
	envGame->game.player_x = 0;
	envGame->game.player_y = 0;
	envGame->mlx.collectables = NULL;
	envGame->mlx.exit = NULL;
	envGame->mlx.char_still = NULL;
	envGame->mlx.wall = NULL;
	envGame->mlx.win = NULL;
	envGame->mlx.mlx = NULL;
	envGame->mlx.bg = NULL;
	envGame->valid.qnt_player = NULL;
	envGame->valid.qnt_collectables = 0;
	envGame->valid.qnt_exit = 0;
	envGame->valid.first_line_len = 0;
}

static int	initialize_game(t_env *envGame)
{
	init_counters(&envGame);
	envGame->game.map = load_map(envGame->fd, &envGame->game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	envGame;

	if (argc != 2 || argv == NULL)
		return (ft_putendl_fd_1("use ./so_long map.ber", 2));
	if (!validate_file_name(argv[1]))
		return (ft_putendl_fd_1("The scroll lacks the '.ber' rune.", 2));
	initialize_game(&envGame);
	valid_map(argv[1], &envGame);
	write(1, "Validado OK - VAMBORA!\n", 24);
	open_screen(&envGame);
	write(1, "Rodando OK - VAMBORA!\n", 23);
	return (0);
}

void	end_game(int error_code)
{


}

void	free_game_resources(t_env *env)
{
	if (env->mlx.win)
	{
		mlx_destroy_window(env->mlx.mlx, env->mlx.win);
		env->mlx.win = NULL;
	}
	if (env->game.map)
		free_map(env->game.map);
	if (env->mlx.mlx)
	{
		free(env->mlx.mlx);
		env->mlx.mlx = NULL;
	}
}
