/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:51:54 by astein            #+#    #+#             */
/*   Updated: 2023/06/11 19:14:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief	checks if the param is an valid int and returns it as a string
 * 
 * @param	a
 * @return	char* 
 */
static char	*check_args_number(char *a)
{
	char	*b;

	b = ft_itoa(ft_atoi(a));
	if (ft_strlen(a) != ft_strlen(b) || ft_strncmp(a, b, ft_strlen(a) != 0))
		dbg_printf(err_block, "Error");
	return (b);
}

static void	check_args_duplicate(int i, char *a, char **argv)
{
	int		j;
	char	*b;

	j = 1;
	while (j < i)
	{
		b = ft_itoa(ft_atoi(argv[j]));
		if (ft_strlen(b) == ft_strlen(a) && ft_strncmp(b, a,
				ft_strlen(argv[j])) == 0)
			dbg_printf(err_block, "Error");
		free(b);
		j++;
	}
}

/**
 *    v = values
 * 			0 = value from args from a to i and then from i to a
 * 			1 = compare value to check dublicates
*/
static void	check_args(int argc, char **argv)
{
	int		i;
	char	*c;

	i = 1;
	if (argc <= 1)
		dbg_printf(err_block, "Error");
	while (i < argc)
	{
		c = check_args_number(argv[i]);
		check_args_duplicate(i, c, argv);
		free(c);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (1);
	stacks->b = NULL;
	check_args(argc, argv);
	stacks->a = ini_stack_a(argc, argv);
	if (!stacks->a)
		return (1);
	dbg_printf(no_block, "stack height: %i", stack_height(stacks->a));
	if (!is_sorted(stacks->a))
		choose_solver(stacks);
	free_stacks(stacks);
	return (0);
}
