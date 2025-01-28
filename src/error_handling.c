/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:40:33 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/01/28 13:55:47 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_handling(int error_code)
{
	char	*err_msg[14];

	err_msg[0] = "Undetected Error =/";
	err_msg[1] = "The scroll lacks the '.beer' rune. Not allowed. ";
	err_msg[2] = "The map layout is cursed and invalid.";
	err_msg[3] = "The exit is unreachable. No valid path exists.";
	err_msg[4] = "You tried to access lands beyond the known plane ";
	err_msg[5] = "Failed to decipher the scroll. it's not empty or enchanted ?";
	err_msg[6] = "Forbidden alchemy detected: division by zero is not allowed.";
	err_msg[7] = "The ritual parameters make no sense.Double-check the inputs.";
	err_msg[8] = "The avatar vanished into the Ether. Sprite load error.";
	err_msg[9] = "The magical lines have failed.";
	err_msg[10] = "An unknown spell has corrupted the game's logic. Try again";
	err_msg[11] = "The enchanted chest you're trying to access is locked.";
	err_msg[12] = "Invalid coordinates: Can't teleport to an undefined space";
	err_msg[13] = "The spellbook is missing critical runes. Reload";
	if (error_code >= 0 && error_code < 14)
		write(1, err_msg[error_code], ft_strlen(err_msg[error_code]));
	return (error_code);
}
