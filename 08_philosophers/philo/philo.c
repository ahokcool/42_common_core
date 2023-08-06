/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:35:53 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 06:23:22 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_state(t_philo *philo)
{
	int	state;

	pthread_mutex_lock(&philo->m_philo);
	state = philo->state;
	pthread_mutex_unlock(&philo->m_philo);
	return (state);
}

t_bool	set_state(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->m_philo);
	if (philo->state == DIED)
	{
		pthread_mutex_unlock(&philo->m_philo);
		return (FALSE);
	}
	philo->state = state;
	if (state == EATING)
	{
		gettimeofday(&philo->t_last_meal, NULL);
		put_msg_id(philo, MSG_ID_EAT, NO_FORK);
	}
	else if (state == FINISHED_EATING)
	{
		gettimeofday(&philo->t_last_meal, NULL);
		philo->count_meals++;
		put_msg_id(philo, MSG_ID_FINISHED_EAT, NO_FORK);
	}
	else if (state == SLEEPING)
		put_msg_id(philo, MSG_ID_SLEEP, NO_FORK);
	else if (state == THINKING)
		put_msg_id(philo, MSG_ID_THINK, NO_FORK);
	else if (state == DIED)
	{
		put_msg_id(philo, MSG_ID_DIED, NO_FORK);
		set_dinner_end(philo->table, TRUE);
	}
	pthread_mutex_unlock(&philo->m_philo);
	return (TRUE);
}

void	*life_of_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (has_started(philo->table) == FALSE)
		;
	pthread_mutex_lock(&philo->m_philo);
	gettimeofday(&philo->t_last_meal, NULL);
	pthread_mutex_unlock(&philo->m_philo);
	if (philo->id % 2 != 0)
		usleep(50);
	while (get_state(philo) != DIED && !has_ended(philo->table))
	{
		if (philo->state == SLEEPING)
			start_eating(philo);
		else if (philo->state == FINISHED_EATING)
			start_thinking(philo);
		else if (philo->state == THINKING)
			start_sleeping(philo);
	}
	return (NULL);
}
