/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:12:47 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/17 14:42:26 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_game	initialize_game(t_game *game)
{
	game->map_h = 0;
	game->map_w = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->map = NULL;

	return (*game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || argv == NULL)
		return (1);
	validate_file_name(argv[1]);
	game = initialize_game(&game);
	valid_map(argv[1], &game);
	write(1, "Validado OK - VAMBORA!\n", 24);
	open_screen(&game);
	write(1, "Rodando OK - VAMBORA!\n", 23);
	return (0);
}
