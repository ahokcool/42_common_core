/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:17:22 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 00:02:40 by astein           ###   ########.fr       */
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

void	print_msg(t_philo *philo, char *msg)
{
	struct timeval	t_curr;

	gettimeofday(&t_curr, NULL);
	pthread_mutex_lock(philo->m_print);
	printf("%ld %d %s\n", t_curr.tv_usec, philo->number, msg);
	pthread_mutex_unlock(philo->m_print);
}
