/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:35:53 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 02:52:43 by astein           ###   ########.fr       */
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
		put_msg(philo, MSG_EAT, NULL);
	else if (state == FINISHED_EATING)
	{
		gettimeofday(&philo->t_last_meal, NULL);
		philo->count_meals++;
		put_extra_msg(philo, MSG_FINISHED_EAT, NULL, CLR_BLUE);
	}
	else if (state == SLEEPING)
		put_msg(philo, MSG_SLEEP, NULL);
	else if (state == THINKING)
		put_msg(philo, MSG_THINK, NULL);
	else if (state == DIED)
	{
		put_msg(philo, MSG_DIED, NULL);
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
	philo->t_last_meal = philo->table->t_start;
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
