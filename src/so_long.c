/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:12:47 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/08 18:18:17 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_counters(t_env *envgame)
{
	envgame->game.map_h = 0;
	envgame->game.map_w = 0;
	envgame->game.player_x = 0;
	envgame->game.player_y = 0;
	envgame->game.moves = 0;
	envgame->game.map = NULL;
	envgame->mlx.collectables = NULL;
	envgame->mlx.exit = NULL;
	envgame->mlx.char_still = NULL;
	envgame->mlx.wall = NULL;
	envgame->mlx.wall = NULL;
	envgame->mlx.win = NULL;
	envgame->mlx.mlx = NULL;
	envgame->mlx.bg = NULL;
	envgame->valid.qnt_player = 0;
	envgame->valid.qnt_collectables = 0;
	envgame->valid.qnt_exit = 0;
	envgame->valid.first_line_len = 0;
	envgame->valid.map_cp = NULL;
}

static int	initialize_game(char *file_name, t_env *envgame)
{
	init_counters(envgame);
	envgame->fd = open(file_name, O_RDONLY);
	envgame->game.map_h = count_lines(envgame->fd);
	envgame->fd = open(file_name, O_RDONLY);
	if (envgame->fd < 0)
	{
		ft_printf("Error: Failed to reopen file.\n");
		return (0);
	}
	envgame->game.map = load_map(envgame);
	close(envgame->fd);
	load_copy(envgame);
	if (!envgame->game.map || !envgame->valid.map_cp)
		return (close_game(envgame, 1, "Copy map not loaded"), 0);
	envgame->fd = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	envgame;

	if (argc != 2 || argv == NULL)
		return (ft_putendl_fd_1("use \"./so_long map.ber \"", 2));
	if (!validate_file_name(argv[1]))
		return (ft_putendl_fd_1("The scroll lacks the '.ber' rune.", 2));
	if (!initialize_game(argv[1], &envgame))
		return (1);
	valid_map(&envgame);
	open_screen(&envgame);
	return (0);
}
