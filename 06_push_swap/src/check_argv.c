/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:27:50 by astein            #+#    #+#             */
/*   Updated: 2023/06/12 17:59:33 by astein           ###   ########.fr       */
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
	// ft_printf("a: %s | b: %s\n", a, b);
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
void	check_args(int argc, char **argv)
{
	int		i;
	char	*a;

	i = 1;
	if (argc <= 1)
		dbg_printf(err_block, "Error");
	while (i < argc)
	{
		a = check_args_number(argv[i]);
		check_args_duplicate(i, a, argv);
		free(a);
		i++;
	}
}
