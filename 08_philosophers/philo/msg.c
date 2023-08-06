/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 00:22:34 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 03:48:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	print_tab(char *msg)
// {
// 	if (msg[10] == 'e')
// 		printf("\t\t\t\t");
// 	else if (msg[10] == ';')
// 		printf("\t\t\t\t\t\t\t");
// 	else if (msg[10] == 't')
// 		printf("\t\t\t\t\t\t\t\t\t\t\t");
// 	else if (msg[10] == 's')
// 		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
// }

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

/**
 * @brief if philo is NULL there has to ba a table
 * 
 * @param philo 
 * @param msg 
 * @param table 
 */
void	put_msg(t_philo *philo, char *msg, t_table *table)
{
	put_msg_fork(philo, msg, table, NO_FORK);
}

void	put_msg_fork(t_philo *philo, char *msg, t_table *table, int fork)
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
			if (PUT_MORE_INFOS)
				print_tab(philo);
			printf("%ld %d %s", get_time_diff(&philo->table->t_start, NULL),
					philo->id, msg);
			if (PUT_MORE_INFOS && msg[10] == ' ' && msg[11] == 't')
				printf("%s\t%d%s", CLR_GREEN, fork, CLR_RESET);
			if (PUT_MORE_INFOS && msg[10] == ' ' && msg[11] == 'd')
				printf("%s\t%d%s", CLR_RED, fork, CLR_RESET);
			printf("\n");
			pthread_mutex_unlock(&philo->table->m_print);
		}
	}
}

void	put_extra_msg(t_philo *philo, char *msg, t_table *table, char *clr)
{
	char	*msg_with_clr;

	if (PUT_MORE_INFOS)
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
