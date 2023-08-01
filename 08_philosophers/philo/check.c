/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:09:12 by astein            #+#    #+#             */
/*   Updated: 2023/08/01 23:12:24 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_times_gt_zero(t_dining_table *dining_table)
{
	if (dining_table->time_die <= 0 || dining_table->time_eat <= 0
		|| dining_table->time_sleep <= 0)
	{
		ft_putstr("Error: Times must be greater than zero\n");
		exit(EXIT_FAILURE);
	}
}

void	check_philos_gt_zero(t_dining_table *dining_table)
{
	if (dining_table->num_philos <= 0)
	{
		ft_putstr("Error: Number of philosophers must be greater than zero\n");
		exit(EXIT_FAILURE);
	}
}

void	check_each_philo_must_eat(t_dining_table *dining_table)
{
	if (dining_table->times_each_philo_must_eat > -2 &&
		dining_table->times_each_philo_must_eat < 1)
	{
		ft_putstr("Error: Times each philosopher must eat must be greater than zero\n");
		exit(EXIT_FAILURE);
	}
}
