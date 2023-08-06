/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:19:54 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 01:34:26 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *a)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (a[i] != '\0')
	{
		if (a[i] >= '0' && a[i] <= '9')
			res = res * 10 + a[i] - '0';
		else
			return (-1);
		i++;
	}
	return (res);
}

/**
 * @brief	This function erases the data in the 'n' bytes of the memory
 * 			starting at the location pointed to by 's', by writing zeros
 * 			to that area.
 * 		
 * @param 	s 
 * @param 	n 
 */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/**
 * @brief	This function  allocates  memory  for  an  array of 'nmemb' elements
 * 			of 'size' bytes each and returns a pointer to the allocated memory.
 * 			The memory is set to zero.
 * 
 * @param 	nmemb 
 * @param 	size 
 * @return 	void* 
 * 				a pointer to the allocated memory
 *				NULL if the allocation fails
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;

	bytes = nmemb * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}

/**
 * @brief	This function calculates the length of a string and returns it
 *
 * @param	s
 * @return	size_t
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief	This function copies 'n' bytes from 'src' to 'dest'.
 * 			The memory areas must not overlap (in this case use 'ft_memmove').
 *
 * @param	dest 
 * @param	src 
 * @param	n		number of bytes which should be copied
 * @return	void*	a pointer to 'dest'
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	d = dest;
	s = src;
	if (!d && !s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
