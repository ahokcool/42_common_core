/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:05:45 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 04:47:03 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ini_dining_table(t_dining_table *dining_table, int argc, char **argv)
{
	dining_table->dinner_started = FALSE;
	dining_table->dinner_over = FALSE;
	dining_table->num_philos = (int)ft_atol(argv[1]);
	dining_table->duration_die = ft_atol(argv[2]);
	dining_table->duration_eat = ft_atol(argv[3]);
	dining_table->duration_sleep = ft_atol(argv[4]);
	dining_table->times_each_philo_must_eat = -2;
	if (argc == 6)
		dining_table->times_each_philo_must_eat = ft_atol(argv[5]);
	check_times_gt_zero(dining_table);
	check_philos_gt_zero(dining_table);
	dining_table->philos = malloc(sizeof(t_philo) * dining_table->num_philos);
	if (!dining_table->philos)
	{
		print_msg(NULL, "Error: mallocing space for philos\n");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_init(&dining_table->m_print, NULL);
	pthread_mutex_init(&dining_table->m_dinner_started, NULL);
	pthread_mutex_init(&dining_table->m_dinner_over, NULL);
}

t_bool	dinning_started(t_dining_table *dining_table)
{
	t_bool	dinner_started;

	pthread_mutex_lock(&dining_table->m_dinner_started);
	dinner_started = dining_table->dinner_started;
	pthread_mutex_unlock(&dining_table->m_dinner_started);
	return (dinner_started);
}

t_bool	dinner_over(t_dining_table *dining_table)
{
	t_bool	dinner_over;

	pthread_mutex_lock(&dining_table->m_dinner_over);
	dinner_over = dining_table->dinner_over;
	pthread_mutex_unlock(&dining_table->m_dinner_over);
	return (dinner_over);
}

void	free_dining_table(t_dining_table *dining_table)
{
	free_philos(dining_table);
	// free(dining_table->philos);
	// pthread_mutex_destroy(&dining_table->m_print);
	// free(dining_table);
}
