/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:58:46 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/01/15 13:28:32 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	initialize_valid_check(t_valid_check *valid_check)
{
	valid_check->first_line_len = 0;
	valid_check->qnt_player = 0;
	valid_check->qnt_collectibles = 0;
	valid_check->qnt_exit = 0;
}

static	int	check_if_is_all_wall(char *line)
{
	while (*line == '1')
		*line++;
	if (*line == '\n')
		return (0);
	else
		return (1);
}

static	int	check_invalid_line(char *line, t_valid_check *valid_list)
{
	if (*line != '1')
		return (1);
	line++;
	while (*line != '\n')
	{
		if (*line == 'P')
			valid_list->qnt_player++;
		else if (*line == 'C')
			valid_list->qnt_collectibles++;
		else if (*line == 'E')
			valid_list->qnt_exit++;
		else if (*line != '0')
			return (1);
		line++;
	}
	if (*(line - 1) != '1' || *line != '\n')
		return (1);
	return (0);
}

int	valid_map(char *map_file)
{
	int				map_fd;
	char			*line;
	t_valid_check	valid_check;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		return (free_map(map_fd, NULL), 1);
	line = get_next_line(map_fd);
	if (!line)
		return (free_map(map_fd, &line), 1);
	initialize_valid_check(&valid_check);
	if (check_if_is_all_wall(line))
		return (free_map(map_fd, &line), 1);
	valid_check.first_line_len = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != valid_check.first_line_len
			|| check_invalid_line(line, &valid_check))
			return (free_map(map_fd, &line), 1);
	}
	close(map_fd);
	return (0);
}
