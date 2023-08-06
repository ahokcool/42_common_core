/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:09:12 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 19:12:23 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philos_gt_zero(t_table *table)
{
	put_extra_msg(&table->m_print, "[check] philos > 0: ...\n", CLR_ORANGE);
	if (table->num_philos <= 0)
		put_exit_msg(table, "[error] check number of philos!\n", FALSE);
	put_extra_msg(&table->m_print, "[check] philos > 0: OK\n", CLR_GREEN);
}

void	check_times_gt_zero(t_table *table)
{
	put_extra_msg(&table->m_print, "[check] times > 0: ...\n", CLR_ORANGE);
	if (table->dur_die <= 0 || table->dur_eat <= 0 || table->dur_sleep <= 0)
		put_exit_msg(table, "[error] check durations (in ms)!\n", FALSE);
	put_extra_msg(&table->m_ended, "[check] times > 0: OK\n", CLR_GREEN);
}

void	check_each_philo_must_eat(t_table *table)
{
	put_extra_msg(&table->m_print,
					"[check] times philo must eat > 0 (or not stated): ...\n",
					CLR_ORANGE);
	if (table->times_philo_must_eat == -1)
		put_exit_msg(table, "[error] check times philo must eat!\n", FALSE);
	put_extra_msg(&table->m_print,
					"[check] times philo must eat > 0 (or not stated): OK\n",
					CLR_GREEN);
}

t_bool	check_if_alive(t_philo *philo)
{
	if(get_state(philo) == EATING)
		return (TRUE);
	if (get_time_diff_last_meal(philo) > philo->table->dur_die)
	{
		set_state(philo, DIED);
		return (FALSE);
	}
	return (TRUE);
}

static int	get_meal_diff(t_philo *philo)
{
	int	diff;

	pthread_mutex_lock(&philo->m_philo);
	diff = philo->count_meals - philo->table->times_philo_must_eat;
	pthread_mutex_unlock(&philo->m_philo);
	return (diff);
}
// wird nur aufgerufen wenn parameter gesetzt wurde
t_bool	check_if_eaten_enough(t_philo *philo)
{
	if (get_meal_diff(philo) >= 0)
		return (TRUE);
	return (FALSE);
}
