/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:35:53 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 00:11:39 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void start_eating(t_philo *philo)
{
	struct timeval	t_curr;

	gettimeofday(&t_curr, NULL);
	if (philo->has_left_fork == FALSE)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = TRUE;
		print_msg(philo, "has taken a fork");
	}
	if (philo->has_right_fork == FALSE)
	{
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = TRUE;
		print_msg(philo, "has taken a fork");
	}
	if (philo->has_left_fork == TRUE && philo->has_right_fork == TRUE)
	{
		philo->state = EATING;
		print_msg(philo, "is eating");
		philo->t_last_meal = t_curr.tv_usec;
		philo->count_meals++;
		usleep(philo->dining_table->duration_eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->has_left_fork = FALSE;
		philo->has_right_fork = FALSE;
	}
}

void	life_of_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->state != DIED)
	{
		if (philo->state == THINKING)
			start_eating(philo);
		else if (philo->state == EATING)
			start_sleeping(philo);
		else if (philo->state == SLEEPING)
			start_thinking(philo);
		}
	}
}
