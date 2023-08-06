/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:05:45 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 23:50:37 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ini_table(t_table *table, int argc, char **argv)
{
	pthread_mutex_init(&table->m_print, NULL);
	pthread_mutex_init(&table->m_started, NULL);
	pthread_mutex_init(&table->m_ended, NULL);
	set_dinner_start(table, FALSE);
	set_dinner_end(table, FALSE);
	table->num_philos = (int)ft_atol(argv[1]);
	table->dur_die = ft_atol(argv[2]);
	table->dur_eat = ft_atol(argv[3]);
	table->dur_sleep = ft_atol(argv[4]);
	table->times_philo_must_eat = -2;
	table->philos = NULL;
	if (argc == 6)
		table->times_philo_must_eat = ft_atol(argv[5]);
	check_times_gt_zero(table);
	check_philos_gt_zero(table);
	check_each_philo_must_eat(table);
}

t_bool	has_started(t_table *table)
{
	t_bool	has_started;

	pthread_mutex_lock(&table->m_started);
	has_started = table->started;
	pthread_mutex_unlock(&table->m_started);
	return (has_started);
}

t_bool	has_ended(t_table *table)
{
	t_bool	has_ended;

	pthread_mutex_lock(&table->m_ended);
	has_ended = table->ended;
	pthread_mutex_unlock(&table->m_ended);
	return (has_ended);
}

void	set_dinner_start(t_table *table, t_bool has_started)
{
	put_extra_msg(NULL, "set dinner start: ...\n", table, CLR_ORANGE);
	pthread_mutex_lock(&table->m_started);
	gettimeofday(&table->t_start, NULL);
	table->started = has_started;
	pthread_mutex_unlock(&table->m_started);
	put_extra_msg(NULL, "set dinner start: OK\n", table, CLR_GREEN);
}

void	set_dinner_end(t_table *table, t_bool has_ended)
{
	int		i;
	t_philo	*cur_philo;

	put_extra_msg(NULL, "set dinner end: ...\n", table, CLR_ORANGE);
	pthread_mutex_lock(&table->m_ended);
	table->ended = has_ended;
	pthread_mutex_unlock(&table->m_ended);
	if (has_ended == TRUE)
	{
		put_extra_msg(NULL, "unlock all forks: ...\n", table, CLR_ORANGE);
		i = 1;
		cur_philo = table->philos;
		while (i <= table->num_philos)
		{
			if(cur_philo->fork_locked == TRUE
			{

			pthread_mutex_unlock(&cur_philo->m_fork);
			}
			cur_philo = cur_philo->right_philo;
			i++;
		}
		put_extra_msg(NULL, "unlock all forks: OK\n", table, CLR_GREEN);
	}
	put_extra_msg(NULL, "set dinner end: OK\n", table, CLR_GREEN);
}
