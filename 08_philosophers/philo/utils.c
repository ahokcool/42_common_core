/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:17:22 by astein            #+#    #+#             */
/*   Updated: 2023/08/01 23:01:11 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Outputs the string 's' to the given file descriptor 'fd'.
 */
void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

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

void	init_philos(t_dining_table *dining_table)
{
	(void)dining_table;
	// External functs. memset, printf, malloc, free, write,
	// usleep, gettimeofday, pthread_create,
	// pthread_detach, pthread_join, pthread_mutex_init,
	// pthread_mutex_destroy, pthread_mutex_lock,
	// pthread_mutex_unlock
}
