/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:17:22 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 03:01:23 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time_diff(struct timeval *t_start, struct timeval *t_end)
{
	long int		sec;
	long int		usec;
	struct timeval	t_curr;

	if (t_end == NULL)
		gettimeofday(&t_curr, NULL);
	else
		t_curr = *t_end;
	sec = t_curr.tv_sec - t_start->tv_sec;
	usec = t_curr.tv_usec - t_start->tv_usec;
	return (sec * 1000 + usec / 1000);
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->dining_table->m_print);
	if (philo == NULL)
		printf("%s\n", msg);
	else
		printf("%ld %d %s\n", get_time_diff(&philo->dining_table->t_start,
					NULL), philo->number, msg);
	pthread_mutex_unlock(&philo->dining_table->m_print);
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
