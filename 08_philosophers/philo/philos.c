/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:53:01 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 01:16:22 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_philo(t_philo *philo, t_table *table)
{
	t_philo	*cur_philo;

	if (table->philos == NULL)
	{
		table->philos = philo;
		philo->left_philo = philo;
		philo->right_philo = philo;
	}
	else
	{
		table->philos->left_philo->right_philo = philo;
		philo->left_philo = table->philos->left_philo;
		philo->right_philo = table->philos;
		table->philos->left_philo = philo;
	}
}

void	ini_philos(t_table *table)
{
	int		i;
	t_philo	*cur_philo;

	i = 1;
	while (i <= table->num_philos)
	{
		cur_philo = malloc(sizeof(t_philo));
		if (!cur_philo)
			put_exit_msg(NULL, "mallocing space for philo", table, FALSE);
		pthread_mutex_init(&cur_philo->m_philo, NULL);
		pthread_mutex_init(&cur_philo->m_fork, NULL);
		set_state(cur_philo, EATING);
		cur_philo->id = i;
		cur_philo->count_meals = 0;
		cur_philo->table = table;
		add_philo(cur_philo, table);
		if (pthread_create(&cur_philo->tid, NULL, life_of_philo, cur_philo))
			put_exit_msg(NULL, "creating thread", table, FALSE);
		cur_philo = NULL;
		i++;
	}
}

void	join_philos(t_table *table)
{
	int		i;
	t_philo	*cur_philo;

	i = 1;
	put_extra_msg(NULL, "joining threads: START\n", table, CLR_ORANGE);
	cur_philo = table->philos;
	while (i <= table->num_philos)
	{
		if (pthread_join(cur_philo->tid, NULL))
			put_exit_msg(NULL, "joining thread", table, FALSE);
		cur_philo = cur_philo->right_philo;
		i++;
	}
	put_extra_msg(NULL, "joining threads: OK\n", table, CLR_GREEN);
}

t_bool	check_if_any_philo_died(t_table *table)
{
	int		i;
	t_philo	*cur_philo;

	i = 1;
	cur_philo = table->philos;
	while (i <= table->num_philos)
	{
		if (check_if_alive(cur_philo) == FALSE)
			return (TRUE);
		cur_philo = cur_philo->right_philo;
		i++;
	}
	return (FALSE);
}

t_bool	check_if_all_philo_have_eaten_enough(t_table *table)
{
	int		i;
	t_philo	*cur_philo;

	if (table->times_philo_must_eat == -2)
		return (FALSE);
	i = 1;
	cur_philo = table->philos;
	while (i <= table->num_philos)
	{
		if (check_if_eaten_enough(cur_philo) == FALSE)
			return (TRUE);
		cur_philo = cur_philo->right_philo;
		i++;
	}
	return (TRUE);
}
