/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:12:47 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/01/28 15:52:05 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || argv == NULL)
		return (1);
	validate_file_name(argv[1]);
	if (valid_map(argv[1]))
		exit(error_handling(2));
	else
		write(1, "Mapa validado!\n", 15);
	return (0);
}
