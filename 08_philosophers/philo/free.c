/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:39:45 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 19:09:47 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table *table)
{
	put_extra_msg(&table->m_print, "free table: ...\n", CLR_ORANGE);
	free_philos(table);
	pthread_mutex_destroy(&table->m_started);
	pthread_mutex_destroy(&table->m_ended);
	pthread_mutex_destroy(&table->m_print);
	free(table);
	put_extra_msg(&table->m_print, "free table: OK\n", CLR_GREEN);
}

void	free_philos(t_table *table)
{
	int		i;
	t_philo	*cur_philo;
	t_philo	*next_philo;

	put_extra_msg(&table->m_print, "free_philos: ...\n", CLR_ORANGE);
	i = 1;
	while (table->philos && i <= table->num_philos)
	{
		cur_philo = table->philos;
		next_philo = cur_philo->right_philo;
		free_philo(cur_philo);
		free(cur_philo);
		cur_philo = NULL;
		table->philos = next_philo;
		i++;
	}
	put_extra_msg(&table->m_print, "free_philos: OK\n", CLR_GREEN);
}

void	free_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->m_philo);
	pthread_mutex_destroy(&philo->m_fork);
}

/**
 * @brief	free the pointer 'ptr'
 * 
 * @param	ptr pointer to be freed
 */
static void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

/**
 * @brief	to simplify the freeing process this function can free
 * 				(symbol 'p')	pointers
 * 				(symbol 'l')	linked lists of the struct type 't_list'
 * 
 * 			EXAMPLE:
 * 				char	*ptr;
 * 				t_list	**lst;
 * 				free_whatever ("pl", ptr, lst);
 * 
 * 			NOTE:	the content of nodes int the list are NOT freed!
 * 
 * @param	str		symols representing the argument types
 * @param	...		arguments to be freed
 * @return	void*	always 'NULL'
 */
void	*free_whatever(char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == 'p')
			free_ptr(va_arg(args, void *));
		else if (*str == 'l')
			ft_lstclear(va_arg(args, t_list **), null_ptr);
		else
			printf("bad param free_whatever: %c\n", str[0]);
		str++;
	}
	va_end(args);
	return (NULL);
}
