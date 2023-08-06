/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:09:12 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 01:34:07 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philos_gt_zero(t_table *table)
{
	put_extra_msg(NULL, "[check] philos > 0: START\n", table, CLR_ORANGE);
	if (table->num_philos <= 0)
	{
		put_msg(NULL, "[error] philos <= 0!\n", table);
		exit_dining(table, FALSE);
	}
	put_extra_msg(NULL, "[check] philos > 0: OK\n", table, CLR_GREEN);
}

void	check_times_gt_zero(t_table *table)
{
	put_extra_msg(NULL, "[check] times > 0: START\n", table, CLR_ORANGE);
	if (table->dur_die <= 0 || table->dur_eat <= 0 || table->dur_sleep <= 0)
	{
		put_msg(NULL, "[error] times <= 0!\n", table);
		exit_dining(table, FALSE);
	}
	put_extra_msg(NULL, "[check] times > 0: OK\n", table, CLR_GREEN);
}

void	check_each_philo_must_eat(t_table *table)
{
	put_extra_msg(NULL,
		"[check] times philo must eat > 0 (or not stated): START\n", table,
		CLR_ORANGE);
	if (table->times_philo_must_eat == -1)
	{
		put_msg(NULL, "[error] times philo must eat <= 0!\n", table);
		exit_dining(table, FALSE);
	}
	put_extra_msg(NULL,
		"[check] times philo must eat > 0 (or not stated): OK\n", table,
		CLR_GREEN);
}

t_bool	check_if_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_philo);
	if (get_time_diff(&philo->t_last_meal, NULL) > philo->table->dur_die)
	{
		pthread_mutex_unlock(&philo->m_philo);
		set_state(philo, DIED);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo->m_philo);
	return (TRUE);
}

// wird nur aufgerufen wenn parameter gesetzt wurde
t_bool	check_if_eaten_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_philo);
	if (philo->count_meals >= philo->table->times_philo_must_eat)
	{
		pthread_mutex_unlock(&philo->m_philo);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->m_philo);
	return (FALSE);
}
