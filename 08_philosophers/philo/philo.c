/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:35:53 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 06:41:20 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Resource hierarchy solution
// https://en.wikipedia.org/wiki/Dining_philosophers_problem#Resource_hierarchy_solution
static void	request_for_forks(t_philo *philo)
{
	if (philo->left_philo->number < philo->number)
	{
		pthread_mutex_lock(&philo->m_philo);
		pthread_mutex_lock(&philo->m_fork);
		pthread_mutex_unlock(&philo->m_philo);
		print_msg(philo, MSG_FORK);
		// philo->has_left_fork = TRUE;
		pthread_mutex_lock(&philo->right_philo->m_philo);
		pthread_mutex_lock(&philo->right_philo->m_fork);
		pthread_mutex_unlock(&philo->right_philo->m_philo);
		print_msg(philo, MSG_FORK);
		// philo->has_right_fork = TRUE;
	}
	else
	{
		pthread_mutex_lock(&philo->right_philo->m_philo);
		pthread_mutex_lock(&philo->right_philo->m_fork);
		pthread_mutex_unlock(&philo->right_philo->m_philo);
		print_msg(philo, MSG_FORK);
		// philo->has_right_fork = TRUE;
		pthread_mutex_lock(&philo->m_philo);
		pthread_mutex_lock(&philo->m_fork);
		pthread_mutex_unlock(&philo->m_philo);
		print_msg(philo, MSG_FORK);
		// philo->has_left_fork = TRUE;
	}
}

static void	start_eating(t_philo *philo)
{
	// start test
	// if (philo->number == 2)
	// {
	// 	pthread_mutex_lock(&philo->m_philo);
	// 	philo->state = THINKING;
	// 	pthread_mutex_unlock(&philo->m_philo);
	// 	return ;
	// }
	// end test
	request_for_forks(philo);
	print_msg(philo, MSG_EAT);
	usleep(philo->duration_eat * 1000);
	// pthread_mutex_lock(&philo->m_philo);
	pthread_mutex_unlock(&philo->m_fork);
	// pthread_mutex_unlock(&philo->m_philo);
	// pthread_mutex_lock(&philo->right_philo->m_philo);
	pthread_mutex_unlock(&philo->right_philo->m_fork);
	// pthread_mutex_unlock(&philo->right_philo->m_philo);
	pthread_mutex_lock(&philo->m_philo);
	gettimeofday(&philo->t_last_meal, NULL);
	philo->count_meals++;
	philo->state = THINKING;
	pthread_mutex_unlock(&philo->m_philo);
}

static void	start_thinking(t_philo *philo)
{
	print_msg(philo, MSG_THINK);
	pthread_mutex_lock(&philo->m_philo);
	philo->state = SLEEPING;
	pthread_mutex_unlock(&philo->m_philo);
}

static void	start_sleeping(t_philo *philo)
{
	print_msg(philo, MSG_SLEEP);
	usleep(philo->duration_sleep * 1000);
	pthread_mutex_lock(&philo->m_philo);
	philo->state = EATING;
	pthread_mutex_unlock(&philo->m_philo);
}

void	*life_of_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (dinning_started(philo->dining_table) == FALSE)
		usleep(100);
	philo->t_last_meal = philo->dining_table->t_start;
	while (philo->state != DIED && is_dinner_over(philo->dining_table) == FALSE)
	{
		if (philo->state == EATING)
			start_eating(philo);
		else if (philo->state == THINKING)
			start_thinking(philo);
		else if (philo->state == SLEEPING)
			start_sleeping(philo);
		// start test
		// if (philo->number == 2)
		// {
		// 	struct timeval	t_curr;
		// 	gettimeofday(&t_curr, NULL);
		// 	printf("last meal     %li\n", philo->t_last_meal.tv_sec);
		// 	printf("now           %li\n", t_curr.tv_sec);
		// 	printf("last meal dif %li\n", get_time_diff(&philo->t_last_meal, NULL));
		// 	printf("die time      %li\n",philo->duration_die);
		// }
		// end test
		if (get_time_diff(&philo->t_last_meal, NULL) > philo->duration_die)
		{
			pthread_mutex_lock(&philo->m_philo);
			philo->state = DIED;
			pthread_mutex_unlock(&philo->m_philo);
			set_dinner_over(philo->dining_table);
			print_msg(philo, MSG_DIED);
			return (NULL);
		}
	}
	return (NULL);
}

void	free_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->m_philo);
}
