/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:53:01 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 05:00:11 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ini_philos(t_dining_table *dining_table)
{
	int		i;
	t_philo	*cur_philo;
	t_philo	*prev_philo;

	i = 1;
	while (i <= dining_table->num_philos)
	{
		cur_philo = malloc(sizeof(t_philo));
		if (!cur_philo)
		{
			print_msg(NULL, "Error: mallocing space for philo");
			exit(EXIT_FAILURE);
		}
		cur_philo->state = THINKING;
		cur_philo->has_left_fork = FALSE;
		cur_philo->has_right_fork = TRUE;
		cur_philo->number = i;
		cur_philo->count_meals = 0;
		cur_philo->t_last_meal = dining_table->t_start;
		cur_philo->duration_die = dining_table->duration_die;
		cur_philo->duration_eat = dining_table->duration_eat;
		cur_philo->duration_sleep = dining_table->duration_sleep;
		cur_philo->dining_table = dining_table;
		if (i == 1)
			dining_table->philos = cur_philo;
		else if (i == dining_table->num_philos)
		{
			prev_philo->right_philo = cur_philo;
			cur_philo->left_philo = prev_philo;
			cur_philo->right_philo = dining_table->philos;
			dining_table->philos->left_philo = cur_philo;
		}
		else
		{
			prev_philo->right_philo = cur_philo;
			cur_philo->left_philo = prev_philo;
		}
		// pthread_mutex_init(&mutex, NULL); // Initialize the mutex
		if (pthread_create(&cur_philo->tid, NULL, life_of_philo,
				cur_philo) != 0)
		{
			print_msg(NULL, "Error: creating thread");
			exit(EXIT_FAILURE);
		}
		// pthread_mutex_destroy(&mutex); // Destroy the mutex
		prev_philo = cur_philo;
		cur_philo = NULL;
		i++;
	}
}

void	join_philos(t_dining_table *dining_table)
{
	int		i;
	t_philo	*cur_philo;

	i = 1;
	while (i <= dining_table->num_philos)
	{
		cur_philo = dining_table->philos;
		pthread_join(cur_philo->tid, NULL);
		cur_philo = cur_philo->right_philo;
		i++;
	}
}

t_bool	check_if_any_philo_died(t_dining_table *dining_table)
{
	int		i;
	t_philo	*cur_philo;

	i = 1;
	cur_philo = dining_table->philos;
	while (i <= dining_table->num_philos)
	{
		pthread_mutex_lock(&cur_philo->m_philo);
		if (cur_philo->state == DIED)
		{
			pthread_mutex_lock(&dining_table->m_dinner_over);
			dining_table->dinner_over = TRUE;
			pthread_mutex_unlock(&dining_table->m_dinner_over);
			print_msg(cur_philo, MSG_DIED);
			return (TRUE);
		}
		// printf("philo no %d is %d\n", cur_philo->number, cur_philo->state);
		pthread_mutex_unlock(&cur_philo->m_philo);
		cur_philo = cur_philo->right_philo;
		i++;
	}
	return (FALSE);
}

t_bool	check_if_all_philo_have_eaten_enough(t_dining_table *dining_table)
{
	int		i;
	t_philo	*cur_philo;

	if (dining_table->times_each_philo_must_eat == -2)
		return (FALSE);
	i = 1;
	cur_philo = dining_table->philos;
	while (i <= dining_table->num_philos)
	{
		pthread_mutex_lock(&cur_philo->m_philo);
		if (cur_philo->count_meals < dining_table->times_each_philo_must_eat)
		{
			pthread_mutex_unlock(&cur_philo->m_philo);
			return (FALSE);
		}
		pthread_mutex_unlock(&cur_philo->m_philo);
		cur_philo = cur_philo->right_philo;
		i++;
	}
	return (TRUE);
}

void	free_philos(t_dining_table *dining_table)
{
	t_philo	*cur_philo;

	printf("start free philos\n");
	while (dining_table->philos != NULL)
	{
		cur_philo = dining_table->philos;
		printf("free philo no %d", cur_philo->number);
		dining_table->philos = dining_table->philos->right_philo;
		free_philo(cur_philo);
		free(cur_philo);
	}
}
