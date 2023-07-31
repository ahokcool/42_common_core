/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:27 by astein            #+#    #+#             */
/*   Updated: 2023/07/31 20:02:35 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
	else if (argc = 5)
	{
		// 1. Get the arguments
		// 2. Create the threads
		// 3. Wait for the threads to finish
		// 4. Destroy the mutexes
		// 5. Free the memory
	}
	else if (argc = 6)
	{
		// 1. Get the arguments
		// 2. Create the threads
		// 3. Wait for the threads to finish
		// 4. Destroy the mutexes
		// 5. Free the memory
	return 0;
}

• Each philosopher has a number ranging from 1 to number_of_philosophers.

number_of_philosophers
time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]

◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

External functs. memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock