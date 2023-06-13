/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_best_friend_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:00:18 by astein            #+#    #+#             */
/*   Updated: 2023/06/13 18:38:01 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

double	get_mean_value(t_stack *stack)
{
	long	sum;
	int		count;

	sum = 0;
	count = 0;
	if (stack == NULL)
		return (0.0);
	while (stack != NULL)
	{
		sum += stack->i;
		count++;
		stack = stack->n;
	}
	return ((double)sum / count);
}

/*
	BUF			0	long		result;
				1	long		cnt_r;
				2	long		cnt_rr;
 
  
*/
long	to_top_b(t_stacks *stacks, unsigned int b, t_bool do_it, t_bool print)
{
	t_stacks	*stacks_cpy;
	long		buf[3];

	stacks_cpy = cpy_stacks(stacks);
	buf[1] = 0;
	buf[2] = 0;
	while (stacks_cpy->b->i != b)
		buf[1] += rb (stacks_cpy, ft_false);
	while (stacks_cpy->b->i != b)
		buf[2] += rrb (stacks_cpy, ft_false);
	free_stacks(stacks_cpy);
	if (buf[1] < buf[2])
		buf[0] = buf[1];
	else
		buf[0] = buf[2];
	if (do_it)
	{
		if (buf[1] < buf[2])
			while (stacks->b->i != b)
				rb (stacks, print);
		else
			while (stacks->b->i != b)
				rrb (stacks, print);
	}
	return (buf[0]);
}

/*
	BUF			0	long		result;
				1	long		cnt_r;
				2	long		cnt_rr;
 
  
*/
long	to_top_a(t_stacks *stacks, unsigned int a, t_bool do_it, t_bool print)
{
	t_stacks	*stacks_cpy;
	long		buf[3];

	stacks_cpy = cpy_stacks(stacks);
	buf[1] = 0;
	buf[2] = 0;
	while (stacks_cpy->a->i != a)
		buf[1] += ra (stacks_cpy, ft_false);
	while (stacks_cpy->a->i != a)
		buf[2] += rra (stacks_cpy, ft_false);
	free_stacks(stacks_cpy);
	if (buf[1] < buf[2])
		buf[0] = buf[1];
	else
		buf[0] = buf[2];
	if (do_it)
	{
		if (buf[1] < buf[2])
			while (stacks->a->i != a)
				ra (stacks, print);
		else
			while (stacks->a->i != a)
				rra (stacks, print);
	}
	return (buf[0]);
}

// long	calc_to_top(t_stacks *stacks, unsigned int a, unsigned int b,
// 		t_bool do_it, t_bool print)
// {
// 	t_stacks	*stacks_cpy[2];
// 	long		result;
// 	long		cnt_r[2];
// 	long		cnt_rr[2];

// 	stacks_cpy[0] = cpy_stacks(stacks);
// 	stacks_cpy[1] = cpy_stacks(stacks);
// 	cnt_r[0] = 0;
// 	cnt_rr[0] = 0;
// 	cnt_r[1] = 0;
// 	cnt_rr[1] = 0;
// 	while (stacks_cpy[0]->a->i != a)
// 		cnt_r[0] += ra (stacks_cpy[0], ft_false);
// 	while (stacks_cpy[0]->b->i != b)
// 		cnt_r[1] += rb (stacks_cpy[0], ft_false);
// 	while (stacks_cpy[1]->a->i != a)
// 		cnt_rr[0] += rra (stacks_cpy[1], ft_false);
// 	while (stacks_cpy[1]->b->i != b)
// 		cnt_rr[1] += rrb (stacks_cpy[1], ft_false);
// 	if (cnt_r[0] < cnt_rr[0])
// 		result = cnt_r[0];
// 	else
// 		result = cnt_rr[0];
// 	if (cnt_r[1] < cnt_rr[1])
// 		result += cnt_r[1];
// 	else
// 		result += cnt_rr[1];
// 	free_stacks(stacks_cpy[0]);
// 	free_stacks(stacks_cpy[1]);
// 	if (do_it)
// 	{
// 		result = 0;
// 		if (cnt_r[0] < cnt_rr[0])
// 			while (stacks->a->i != a)
// 				result += ra (stacks, print);
// 		else
// 			while (stacks->a->i != a)
// 				result += rra (stacks, print);
// 		if (cnt_r[1] < cnt_rr[1])
// 			while (stacks->b->i != b)
// 				result += rb (stacks, print);
// 		else
// 			while (stacks->b->i != b)
// 				result += rrb (stacks, print);
// 	}
// 	return (result);
// }

/*
	cur		0	cur_a
			1	cur_b
			2	bf
*/
void	do_best_friend(t_stacks *stacks, t_bool print, long *count_actions)
{
	t_stack	*s[3];

	s[0] = stacks->a;
	while (s[0])
	{
		s[1] = stacks->b;
		s[2] = s[1];
		while (s[1])
		{
			if ((long)(s[0]->i - s[1]->i) > 0
				&& (long)(s[0]->i - s[1]->i) < (long)(s[0]->i - s[2]->i))
				s[2] = s[1];
			s[1] = s[1]->n;
		}
		s[0]->bf = s[2];
		// s[0]->bf_c = calc_to_top(stacks, s[0]->i, s[2]->i, ft_false, ft_false);
		s[0]->bf_c = to_top_a(stacks, s[0]->i, ft_false, ft_false) + to_top_b(stacks, s[2]->i, ft_false, ft_false);
		s[0] = s[0]->n;
	}
	s[0] = stacks->a;
	s[2] = s[0];
	while (s[0])
	{
		if (s[0]->bf_c < s[2]->bf_c)
			s[2] = s[0];
		s[0] = s[0]->n;
	}
	// *count_actions += calc_to_top(stacks, s[2]->i, s[2]->bf->i, ft_true, print);
	*count_actions += to_top_a(stacks, s[2]->i, ft_true, print) + to_top_b(stacks, s[2]->bf->i, ft_true, print);
	*count_actions += pa(stacks, print);
}

