/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:12:47 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/03/20 16:30:04 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_counters(t_env *envGame)
{
	envGame->game.map_h = 0;
	envGame->game.map_w = 0;
	envGame->game.player_x = 0;
	envGame->game.player_y = 0;
	envGame->game.moves = 0;
	envGame->game.map = NULL;
	envGame->mlx.collectables = NULL;
	envGame->mlx.exit = NULL;
	envGame->mlx.char_still = NULL;
	envGame->mlx.wall = NULL;
	envGame->mlx.win = NULL;
	envGame->mlx.mlx = NULL;
	envGame->mlx.bg = NULL;
	envGame->valid.qnt_player = 0;
	envGame->valid.qnt_collectables = 0;
	envGame->valid.qnt_exit = 0;
	envGame->valid.first_line_len = 0;
}

static int	initialize_game(char *file_name, t_env *envGame)
{
	init_counters(envGame);
	envGame->fd = open(file_name, O_RDONLY);
	envGame->game.map_h = count_lines(envGame->fd);
	envGame->fd = open(file_name, O_RDONLY);
	if (envGame->fd < 0)
	{
		ft_printf("Error: Failed to reopen file.\n");
		return (0);
	}
	envGame->game.map = load_map(envGame);
	if (!envGame->game.map)
	{
		ft_printf("Error: Map not loaded.\n");
		return (close_game(envGame, 1), 0);
	}
	close(envGame->fd);
	envGame->fd = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	envGame;

	if (argc != 2 || argv == NULL)
		return (ft_putendl_fd_1("use \"./so_long map.ber \"", 2));
	if (!validate_file_name(argv[1]))
		return (ft_putendl_fd_1("The scroll lacks the '.ber' rune.", 2));
	initialize_game(argv[1], &envGame);
	valid_map(&envGame);
	write(1, "Validado OK - VAMBORA!\n", 24);
	open_screen(&envGame);
	write(1, "Rodando OK - VAMBORA!\n", 23);
	return (0);
}
