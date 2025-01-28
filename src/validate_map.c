/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:58:46 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/01/28 16:18:43 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_map(char *map_file)
{
	int				map_fd;
	t_game			game;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		return (free_map(map_fd, NULL), 1);
	game.map_height = count_lines(map_fd);
	game.map = load_map(map_fd, &game);
	//validate
	if (!game.map)
		return (free_map(map_fd, NULL), 1);
	close(map_fd);
	return (0);
}

// int	flood_fill(char **map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;

// }

void	validate_file_name(char *name)
{
	size_t	name_len;
	size_t	ext_len;
	size_t	comparation;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(".ber");
	comparation = ft_strncmp(name + name_len - ext_len, ".ber", ext_len);
	if (name_len <= ext_len || comparation != 0)
		exit (error_handling(1));
}
