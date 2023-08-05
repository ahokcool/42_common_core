/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:17:22 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 19:46:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time_diff(struct timeval *t_start, struct timeval *t_end)
{
	long int		sec;
	long int		usec;
	struct timeval	t_curr;

	if (t_end == NULL)
		gettimeofday(&t_curr, NULL);
	else
		t_curr = *t_end;
	sec = t_curr.tv_sec - t_start->tv_sec;
	usec = t_curr.tv_usec - t_start->tv_usec;
	return (sec * 1000 + usec / 1000);
}

/**
 * @brief if philo is NULL there has to ba a dining_table
 * 
 * @param philo 
 * @param msg 
 * @param dining_table 
 */
void	print_msg(t_philo *philo, char *msg, t_dining_table *dining_table)
{
	if (philo == NULL)
	{
		pthread_mutex_lock(&dining_table->m_print);
		printf("%s", msg);
		pthread_mutex_unlock(&dining_table->m_print);
	}
	else
	{
		if (!is_dinner_over(philo->dining_table))
		{
			if(philo->state == DIED)
				set_dinner_over(philo->dining_table);
			pthread_mutex_lock(&philo->dining_table->m_print);
			printf("%ld %d %s\n", get_time_diff(&philo->dining_table->t_start,
						NULL), philo->number, msg);
			pthread_mutex_unlock(&philo->dining_table->m_print);
		}
	}
}

void	print_additional_msg(t_philo *philo, char *msg,
		t_dining_table *dining_table, char *clr)
{
	char	*msg_with_clr;

	if (PRINT_MORE_INFOS)
	{
		msg_with_clr = ft_strcat_multi(3, clr, msg, CLR_RESET);
		print_msg(philo, msg_with_clr, dining_table);
		free(msg_with_clr);
	}
}


/**
 * @brief	Allocates and returns a newstring, which is the result of the
 * 			concatenation of the Strings 's1' and 's2'.
 *
 * @param	s1	The prefix string.
 * @param	s2	The suffix string.
 * @return char*
 * 				The new string
 * 				NULL if the allocation fails
 */
/* 
char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s3;
	size_t s1_len;
	size_t s2_len;
	size_t total_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	s3 = malloc(total_len);
	if (!s3)
		return (NULL);
	if (total_len != 1)
	{
		ft_memcpy(s3, s1, s1_len);
		ft_memcpy(&s3[s1_len], s2, s2_len);
	}
	s3[total_len - 1] = 0;
	return (s3);
}
 */