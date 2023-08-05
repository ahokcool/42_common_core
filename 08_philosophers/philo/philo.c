/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:35:53 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 04:57:46 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_philo);
	print_msg(philo, MSG_THINK);
	philo->state = EATING;
	pthread_mutex_unlock(&philo->m_philo);
}

static void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_philo);
	print_msg(philo, MSG_EAT);
	gettimeofday(&philo->t_last_meal, NULL);
	philo->count_meals++;
	// test
	if (philo->number == 1)
		philo->state = EATING;
	else
		philo->state = DIED;
	pthread_mutex_unlock(&philo->m_philo);
	usleep(philo->duration_eat * 1000);
}

static void	start_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_philo);
	print_msg(philo, MSG_SLEEP);
	philo->state = THINKING;
	pthread_mutex_unlock(&philo->m_philo);
	usleep(philo->duration_sleep * 1000);
}

void	*life_of_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (dinning_started(philo->dining_table) == FALSE)
		usleep(100);
	while (philo->state != DIED && dinner_over(philo->dining_table) == FALSE)
	{
		if (philo->state == THINKING)
			start_eating(philo);
		else if (philo->state == EATING)
			start_sleeping(philo);
		else if (philo->state == SLEEPING)
			start_thinking(philo);
	}
	return (NULL);
}

void	free_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->m_philo);
}
