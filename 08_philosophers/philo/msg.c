/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:22:34 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 01:32:18 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief if philo is NULL there has to ba a table
 * 
 * @param philo 
 * @param msg 
 * @param table 
 */
void	put_msg(t_philo *philo, char *msg, t_table *table)
{
	if (philo == NULL)
	{
		pthread_mutex_lock(&table->m_print);
		printf("%s", msg);
		pthread_mutex_unlock(&table->m_print);
	}
	else
	{
		if (!has_ended(philo->table))
		{
			pthread_mutex_lock(&philo->table->m_print);
			printf("%ld %d %s\n", get_time_diff(&philo->table->t_start, NULL),
				philo->id, msg);
			pthread_mutex_unlock(&philo->table->m_print);
		}
	}
}

void	put_extra_msg(t_philo *philo, char *msg, t_table *table, char *clr)
{
	char	*msg_with_clr;

	if (PRINT_MORE_INFOS)
	{
		msg_with_clr = ft_strcat_multi(3, clr, msg, CLR_RESET);
		put_msg(philo, msg_with_clr, table);
		free(msg_with_clr);
	}
}

void	put_exit_msg(t_philo *philo, char *msg, t_table *table, t_bool success)
{
	char	*msg_with_clr;

	if (success)
		msg_with_clr = ft_strcat_multi(4, "[exit] ", CLR_GREEN, msg, CLR_RESET);
	else
		msg_with_clr = ft_strcat_multi(4, "[exit] ", CLR_RED, msg, CLR_RESET);
	put_msg(philo, msg_with_clr, table);
	free(msg_with_clr);
	exit_dining(table, success);
}
