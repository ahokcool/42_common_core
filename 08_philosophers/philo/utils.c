/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:17:22 by astein            #+#    #+#             */
/*   Updated: 2023/08/02 18:20:38 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Outputs the string 's' to the given file descriptor 'fd'.
 */
void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
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

void	init_philos(t_dining_table *dining_table)
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
			ft_putstr("Error: mallocing space for philo");
			exit(EXIT_FAILURE);
		}
		cur_philo->state = THINKING;
		cur_philo->has_left_fork = FALSE;
		cur_philo->has_right_fork = TRUE;
		cur_philo->number = i;
		prev_philo->right_philo = cur_philo;
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
		prev_philo = cur_philo;
	

		CONTINUE HERE TO INIYIALIZE THE THREADS
	
		// pthread_mutex_init(&mutex, NULL); // Initialize the mutex
		// pthread_create(&tid, NULL, philo_start_livin, NULL);
		// pthread_join(tid, NULL); // Wait for the thread to finish
		// pthread_mutex_destroy(&mutex); // Destroy the mutex
		i++;
	}
	// External functs. memset, printf, malloc, free, write,
	// usleep, gettimeofday, pthread_create,
	// pthread_detach, pthread_join, pthread_mutex_init,
	// pthread_mutex_destroy, pthread_mutex_lock,
	// pthread_mutex_unlock
}
