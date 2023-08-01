/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:05:45 by astein            #+#    #+#             */
/*   Updated: 2023/08/01 23:07:29 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ini_dining_table(t_dining_table *dining_table, int argc, char **argv)
{
	dining_table->num_philos = (int)ft_atol(argv[1]);
	dining_table->time_die = ft_atol(argv[2]);
	dining_table->time_eat = ft_atol(argv[3]);
	dining_table->time_sleep = ft_atol(argv[4]);
	dining_table->times_each_philo_must_eat = -2;
	if (argc == 6)
		dining_table->times_each_philo_must_eat = ft_atol(argv[5]);
	check_times_gt_zero(dining_table);
	check_philos_gt_zero(dining_table);
}
