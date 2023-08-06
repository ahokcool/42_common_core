/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:01:28 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 05:32:24 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Resource hierarchy solution
// https://en.wikipedia.org/wiki/Dining_philosophers_problem
t_bool	request_for_forks(t_philo *philo)
{
	if (philo->right_philo->id > philo->id)
	{
		pthread_mutex_lock(&philo->m_fork);
		if (has_ended(philo->table))
			return (FALSE);
		put_msg_id(philo, MSG_ID_FORK, philo->id);
		pthread_mutex_lock(&philo->right_philo->m_fork);
		if (has_ended(philo->table))
			return (FALSE);
		put_msg_id(philo, MSG_ID_FORK, philo->right_philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->right_philo->m_fork);
		if (has_ended(philo->table))
			return (FALSE);
		put_msg_id(philo, MSG_ID_FORK, philo->right_philo->id);
		pthread_mutex_lock(&philo->m_fork);
		if (has_ended(philo->table))
			return (FALSE);
		put_msg_id(philo, MSG_ID_FORK, philo->id);
	}
	return (TRUE);
}

void	start_eating(t_philo *philo)
{
	if (!request_for_forks(philo))
		return ;
	if (set_state(philo, EATING) == FALSE)
		return ;
	usleep(philo->table->dur_eat * 1000);
	if (set_state(philo, FINISHED_EATING) == FALSE)
		return ;
	if (PUT_MORE_INFOS)
		put_msg_id(philo, MSG_ID_FORK_DROP, philo->id);
	pthread_mutex_unlock(&philo->m_fork);
	if (PUT_MORE_INFOS)
		put_msg_id(philo, MSG_ID_FORK_DROP, philo->right_philo->id);
	pthread_mutex_unlock(&philo->right_philo->m_fork);
}

void	start_thinking(t_philo *philo)
{
	if (set_state(philo, THINKING) == FALSE)
		return ;
}

void	start_sleeping(t_philo *philo)
{
	if (set_state(philo, SLEEPING) == FALSE)
		return ;
	usleep(philo->table->dur_sleep * 1000);
}
