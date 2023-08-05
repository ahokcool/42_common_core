/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:27 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 20:49:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_program(t_dining_table *dining_table, t_bool success)
{
	join_philos(dining_table);
	// sleep(1);
	if (success)
		print_additional_msg(NULL, "exit_program\n", dining_table, CLR_GREEN);
	else
		print_additional_msg(NULL, "exit_program\n", dining_table, CLR_RED);
	if (dining_table)
	{
		free_dining_table(dining_table);
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
	ini_philos(dining_table);
	// sleep(1);
	set_dinner_start(dining_table);
	while (1)
	{
		// printf("   -> check");
		if (check_if_any_philo_died(dining_table))
		{
			// printf("dinner_over: %d\n", dining_table->dinner_over);
			exit_program(dining_table, FALSE);
		}
		if (check_if_all_philo_have_eaten_enough(dining_table))
		{
			// printf("   -> END OF DINNER\n");
			set_dinner_over(dining_table);
			exit_program(dining_table, TRUE);
		}
		// usleep(100);
	}
}
