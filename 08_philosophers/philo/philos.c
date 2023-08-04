/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:53:01 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 00:01:54 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
		cur_philo->count_meals = 0;
		cur_philo->t_last_meal = dining_table->t_start;
		cur_philo->m_print = &dining_table->m_print;
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

t_bool check_if_any_philo_died(t_dining_table *dining_table)
{
	int		i;
	t_philo	*cur_philo;

	i = 1;
	while (i <= dining_table->num_philos)
	{
		cur_philo = dining_table->philos;
		pthread_mutex_lock(&cur_philo->m_state);
		if (cur_philo->state == DIED)
		{
			
			pthread_mutex_lock(&dining_table->m_print);
			printf("%ld %d %s\n", get_time(dining_table), cur_philo->number, MSG_DIED);
			pthread_mutex_unlock(&dining_table->m_print);
			return (TRUE);
		}
		pthread_mutex_unlock(&cur_philo->m_state);
		cur_philo = cur_philo->right_philo;
		i++;
	}
	return (FALSE);
}