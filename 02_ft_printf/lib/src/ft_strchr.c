/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:45:20 by astein            #+#    #+#             */
/*   Updated: 2023/04/21 16:24:26 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief	This function returns a pointer to the first occurrence of the
 * 			character 'c' in the string 's'.
 * 
 * @param	s 
 * @param	c 
 * @return	char*
 * 				pointer to the matching byte
 * 				NULL if 'c' does not occur in 's'
 */
char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
