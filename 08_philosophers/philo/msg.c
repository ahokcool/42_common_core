/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 00:22:34 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 06:10:14 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_tab(t_philo *philo)
{
	int	i;

	if (philo->table->num_philos <= 10)
	{
		i = 1;
		while (i < philo->id)
		{
			printf("\t\t");
			i++;
		}
	}
}

static void	put_msg(pthread_mutex_t *m_print, char *msg, char *clr)
{
	pthread_mutex_lock(m_print);
	printf("%s%s%s", clr, msg, CLR_RESET);
	pthread_mutex_unlock(m_print);
}

void	put_msg_id(t_philo *philo, int msg_id, int fork)
{
	if (!has_ended(philo->table))
	{
		pthread_mutex_lock(&philo->table->m_print);
		if (PUT_MORE_INFOS)
			print_tab(philo);
		printf("%ld %d %s", get_time_diff(&philo->table->t_start),
				philo->id, get_msg(msg_id));
		if (PUT_MORE_INFOS && msg_id == MSG_ID_FORK)
			printf("%s\t%d%s", CLR_GREEN, fork, CLR_RESET);
		if (PUT_MORE_INFOS && msg_id == MSG_ID_FORK_DROP)
			printf("%s\t%d%s", CLR_RED, fork, CLR_RESET);
		printf("\n");
		pthread_mutex_unlock(&philo->table->m_print);
	}
}

void	put_extra_msg(pthread_mutex_t *m_print, char *msg, char *clr)
{
	if (PUT_MORE_INFOS)
		put_msg(m_print, msg, clr);
}

void	put_exit_msg(t_table *table, char *msg, t_bool success)
{
	if (success)
		put_msg(&table->m_print, msg, CLR_GREEN);
	else
		put_msg(&table->m_print, msg, CLR_RED);
	exit_dining(table, success);
}
