/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:27 by astein            #+#    #+#             */
/*   Updated: 2023/08/02 18:07:26 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// //an idea for the forks
// pthread_mutex_t mutex;

// void *philo_start_livin(void *arg) {
// 	pthread_mutex_lock(&mutex); // Lock the mutex
// 	pthread_mutex_unlock(&mutex); // Unlock the mutex
// 	return (NULL);
// }

// struct timeval currentTime;
// gettimeofday(&currentTime, NULL);

// pthread_t tid;
// pthread_mutex_init(&mutex, NULL); // Initialize the mutex
// pthread_create(&tid, NULL, philo_start_livin, NULL);
//last parameter can pass data to the thread so maybe i will pass the forks
// pthread_join(tid, NULL); // Wait for the thread to finish
// pthread_mutex_destroy(&mutex); // Destroy the mutex

static void	check_args_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_dining_table	*dining_table;

	dining_table = malloc(sizeof(t_dining_table));
	if (!dining_table)
		return (EXIT_FAILURE);
	check_args_count(argc);
	ini_dining_table(dining_table, argc, argv);
	init_philos(dining_table);
}
