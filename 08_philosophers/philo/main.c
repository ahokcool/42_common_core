/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:27 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 01:59:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
		put_exit_msg(NULL, "wrong number of arguments\n", NULL, FALSE);
	table = malloc(sizeof(t_table));
	if (!table)
		put_exit_msg(NULL, "malloc for table failed\n", NULL, FALSE);
	ini_table(table, argc, argv);
	ini_philos(table);
	set_dinner_start(table, TRUE);
	while (1)
	{
		if (check_if_any_philo_died(table))
			exit_dining(table, FALSE);
		if (check_if_all_philo_have_eaten_enough(table))
			exit_dining(table, TRUE);
		usleep(1000);
	}
}

void	exit_dining(t_table *table, t_bool success)
{
	put_extra_msg(NULL, "exit dinner: ...\n", table, CLR_ORANGE);
	if (!table)
		exit(EXIT_FAILURE);
	set_dinner_end(table, TRUE);
	join_philos(table);
	if (table)
		free_table(table);
	put_extra_msg(NULL, "exit dinner: OK\n", table, CLR_GREEN);
	if (success)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
