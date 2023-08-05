/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:09:12 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 20:57:47 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_times_gt_zero(t_dining_table *dining_table)
{
	print_additional_msg(NULL, "check if all times are greater then 0: ",
			dining_table, CLR_ORANGE);
	if (dining_table->duration_die <= 0 || dining_table->duration_eat <= 0
		|| dining_table->duration_sleep <= 0)
	{
		print_msg(NULL, "Error: Times must be greater than zero\n",
				dining_table);
		exit(EXIT_FAILURE);
	}
	print_additional_msg(NULL, "OK\n", dining_table, CLR_GREEN);
}

void	check_philos_gt_zero(t_dining_table *dining_table)
{
	print_additional_msg(NULL, "check if number of philos is greater then 0: ",
			dining_table, CLR_ORANGE);
	if (dining_table->num_philos <= 0)
	{
		print_msg(NULL,
					"Error: Number of philosophers must be greater than zero\n",
					dining_table);
		exit(EXIT_FAILURE);
	}
	print_additional_msg(NULL, "OK\n", dining_table, CLR_GREEN);
}

void	check_each_philo_must_eat(t_dining_table *dining_table)
{
	print_additional_msg(NULL,
			"check if times each philo must eat is alright: ", dining_table,
			CLR_ORANGE);
	if (dining_table->times_each_philo_must_eat == -1)
	{
		print_msg(NULL,
					"Error: Times each philosopher must eat must be greater than zero\n",
					dining_table);
		exit(EXIT_FAILURE);
	}
	print_additional_msg(NULL, "OK\n", dining_table, CLR_GREEN);
}
