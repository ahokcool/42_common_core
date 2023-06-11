/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:45:44 by astein            #+#    #+#             */
/*   Updated: 2023/06/11 19:15:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*buffer_node;

	if (!(*stack))
		return ;
	if ((*stack)->n)
	{
		buffer_node = *stack;
		while ((*stack)->n)
			*stack = (*stack)->n;
		(*stack)->n = buffer_node;
		*stack = buffer_node->n;
		buffer_node->n = NULL;
	}
}

long	ra(t_stack **a, t_bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
	return (1);
}

long	rb(t_stack **b, t_bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
	return (1);
}

long	rr(t_stack **a, t_stack **b, t_bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
	return (1);
}
