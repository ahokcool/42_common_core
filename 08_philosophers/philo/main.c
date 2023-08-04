/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:27 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 00:06:52 by astein           ###   ########.fr       */
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

void	exit_program(t_dining_table *dining_table, t_bool success)
{
	if (dining_table)
	{
		free(dining_table);
	}
	if (success)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

static void	check_args_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_dining_table	*dining_table;

	check_args_count(argc);
	dining_table = malloc(sizeof(t_dining_table));
	if (!dining_table)
		return (EXIT_FAILURE);
	ini_dining_table(dining_table, argc, argv);
	init_philos(dining_table);


	while(1)
	{
		//check if any philo died
		usleep(1000);
	}
}
