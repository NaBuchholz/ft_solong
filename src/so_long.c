/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:12:47 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/03 17:48:15 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || argv == NULL)
		return (1);
	validate_file_name(argv[1]);
	valid_map(argv[1]);
	write(1, "Ate agora tudo bem, VAMBORA!\n",30);
	return (0);
}
