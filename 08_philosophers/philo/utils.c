/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:17:22 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 01:15:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time_diff(struct timeval *t1, struct timeval *t2)
{
	long int		sec;
	long int		usec;
	struct timeval	t_curr;

	if (t2 == NULL)
		gettimeofday(&t_curr, NULL);
	else
		t_curr = *t2;
	sec = t_curr.tv_sec - t1->tv_sec;
	usec = t_curr.tv_usec - t1->tv_usec;
	return (sec * 1000 + usec / 1000);
}
