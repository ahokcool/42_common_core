/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:02:46 by astein            #+#    #+#             */
/*   Updated: 2023/06/12 20:13:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stacks	*stacks)
{
	if (!is_sorted(stacks->a))
		ra(stacks, ft_true);
}

void	sort_three(t_stacks	*s)
{
	int		a;
	int		b;
	int		c;

	a = s->a->i;
	b = s->a->n->i;
	c = s->a->n->n->i;
	if (a > b && b < c && c > a)
		sa(s, ft_true);
	else if (a > b && b < c && c < a)
		ra(s, ft_true);
	else if (a < b && b > c && c < a)
		rra(s, ft_true);
	else if (a > b && b > c && c < a)
	{
		sa(s, ft_true);
		rra(s, ft_true);
	}
	else if (a < b && b > c && c > a)
	{
		sa(s, ft_true);
		ra(s, ft_true);
	}
}

/**
 * @brief	checks if ra or rra is more efficient to bring the element with
 * 			the index i to the top.
 * 
 * 			NOTE:
 * 					- only made for stack heights 4 and 5
 * 					- only made for stack a
 * 
 * @param stack	the stack
 * @param i 	the index that should be brought on top
 */
static void	push_to_top(t_stacks *stacks, unsigned int i)
{
	if (stacks->a->i == i || stacks->a->n->i == i || stacks->a->n->n->i == i)
	{
		while (stacks->a->i != i)
			ra(stacks, ft_true);
	}
	else
	{
		while (stacks->a->i != i)
			rra(stacks, ft_true);
	}
}

/*
	index 0 push b
	index 1 push b
	3 sortieren
	pa
	pa
	
*/
void	sort_five(t_stacks	*stacks)
{
	if (stack_height(stacks->a) == 5)
	{
		push_to_top(stacks, 0);
		pb(stacks, ft_true);
		push_to_top(stacks, 1);
		pb(stacks, ft_true);
		sort_three(stacks);
		pa(stacks, ft_true);
		pa(stacks, ft_true);
	}
	else
		dbg_printf(err_block, "sort 5 function with a stack != 5 elements!");
}
