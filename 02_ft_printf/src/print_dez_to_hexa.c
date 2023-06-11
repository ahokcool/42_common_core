/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dez_to_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:39:19 by astein            #+#    #+#             */
/*   Updated: 2023/04/24 19:57:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_dez_to_hexa(unsigned long dez_nbr, int *len, t_bool caps)
{
	if (dez_nbr < 16)
	{
		if (caps)
			print_char(HEXA_UPPER[dez_nbr], len);
		else
			print_char(HEXA_LOWER[dez_nbr], len);
		return ;
	}
	else
		print_dez_to_hexa((dez_nbr / 16), len, caps);
	print_dez_to_hexa((dez_nbr % 16), len, caps);
}
