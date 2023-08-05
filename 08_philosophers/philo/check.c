/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:09:12 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 02:22:50 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_times_gt_zero(t_dining_table *dining_table)
{
	if (dining_table->duration_die <= 0 || dining_table->duration_eat <= 0
		|| dining_table->duration_sleep <= 0)
	{
		print_msg(NULL, "Error: Times must be greater than zero\n");
		exit(EXIT_FAILURE);
	}
}

void	check_philos_gt_zero(t_dining_table *dining_table)
{
	if (dining_table->num_philos <= 0)
	{
		print_msg(NULL,
					"Error: Number of philosophers must be greater than zero\n");
		exit(EXIT_FAILURE);
	}
}

void	check_each_philo_must_eat(t_dining_table *dining_table)
{
	if (dining_table->times_each_philo_must_eat > -2 &&
		dining_table->times_each_philo_must_eat < 1)
	{
		print_msg(NULL,
					"Error: Times each philosopher must eat must be greater than zero\n");
		exit(EXIT_FAILURE);
	}
}
