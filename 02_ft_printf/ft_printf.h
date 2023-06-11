/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:09:06 by astein            #+#    #+#             */
/*   Updated: 2023/04/24 20:01:03 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "lib/libft.h"
# include <stdarg.h>

//******************************************************************************
// Hexadecimal Value Definitions
//******************************************************************************
# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"

//******************************************************************************
//			Typedefs
//******************************************************************************
typedef enum e_bool
{
	ft_false = 0,
	ft_true = 1
}		t_bool;

//******************************************************************************
//			ft_printf
//******************************************************************************
int		ft_printf(const char *str, ...);

//******************************************************************************
//			Other print functions
//******************************************************************************
void	print_char(char c, int *len);
void	print_str(char *str, int *len);
void	print_dez_to_hexa(unsigned long dez_nbr, int *len, t_bool caps);
void	print_ptr(unsigned long ptr, int *len);
void	print_nbr(long nbr, int *len);

#endif
