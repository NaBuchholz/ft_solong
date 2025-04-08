/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:58:46 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/07 21:55:46 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	valid_map(t_env *envGame)
{
	if (!envGame->game.map)
		close_game(envGame, 2);
	if (is_rectangle(envGame->game))
		close_game(envGame, 2);
	if (valid_chars(&envGame->game, &envGame->valid))
		close_game(envGame, 5);
	if (!flood_fill(envGame, envGame->game.player_x, envGame->game.player_y))
		close_game(envGame, 9);

}

int	validate_file_name(char *name)
{
	size_t	name_len;
	size_t	ext_len;
	size_t	comparation;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(".ber");
	comparation = ft_strncmp(name + name_len - ext_len, ".ber", ext_len);
	if (name_len <= ext_len || comparation != 0)
		return (0);
	return (1);
}

int	is_rectangle(t_game game)
{
	int	x;

	if (game.map_h == game.map_w)
		return (1);
	x = 0;
	while (x < game.map_h)
	{
		if ((int)ft_strlen(game.map[x]) - 1 != game.map_w)
			return (1);
		x++;
	}
	return (0);
}
