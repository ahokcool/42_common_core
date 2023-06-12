/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:08:51 by astein            #+#    #+#             */
/*   Updated: 2023/06/12 20:47:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

typedef long (t_action_ptr)(t_stacks*, t_bool);

typedef struct s_action
{
	char			*name;
	t_action_ptr	*action;
}					t_action;

typedef struct s_all_actions
{
	t_action	a[11];
}				t_all_actions;

static void	set_all_actions(t_all_actions	*all_actions)
{
	all_actions->a[0].name = "pa";
	all_actions->a[0].action = pa;
	all_actions->a[1].name = "pb";
	all_actions->a[1].action = pb;
	all_actions->a[2].name = "sa";
	all_actions->a[2].action = sa;
	all_actions->a[3].name = "sb";
	all_actions->a[3].action = sb;
	all_actions->a[4].name = "ss";
	all_actions->a[4].action = ss;
	all_actions->a[5].name = "ra";
	all_actions->a[5].action = ra;
	all_actions->a[6].name = "rb";
	all_actions->a[6].action = rb;
	all_actions->a[7].name = "rr";
	all_actions->a[7].action = rr;
	all_actions->a[8].name = "rra";
	all_actions->a[8].action = rra;
	all_actions->a[9].name = "rrb";
	all_actions->a[9].action = rrb;
	all_actions->a[10].name = "rrr";
	all_actions->a[10].action = rrr;
}

static t_all_actions	*ini_actions(void)
{
	t_all_actions	*all_actions;
	// int				i;

	all_actions = malloc(sizeof(t_all_actions));
	if (!all_actions)
		dbg_printf(err_block, "malloc failed!");
	// i = 0;
	// while (i < 10)
	// {
	// 	all_actions[i] = malloc(sizeof(s_action));
	// 	if (!all_actions[i])
	// 		dbg_print(err_block, "malloc failed!");
	// 	i++;
	// }
	set_all_actions(all_actions);
	return (all_actions);
}

static void	call_action(t_stacks *stacks, char *cmd, t_all_actions *all_actions)
{
	t_action_ptr	*action_ptr;
	int				i;

	i = 0;
	action_ptr = NULL;
	while (i < 11)
	{
		if (ft_strncmp(all_actions->a[i].name, cmd, ft_strlen(cmd) -1) == 0)// && cmd[ft_strlen(cmd) - 1] == '\n')
			action_ptr = all_actions->a[i].action;
		i++;
	}
	if (action_ptr != NULL)
		action_ptr(stacks, ft_false);
	else
		dbg_printf(err_block, "Error");
}

// void	str2action(t_stacks *stacks, char *cmd)
// {
// 	(void)stacks;
// 	if (ft_strlen(cmd) == 3)
// 	{
// 		if (ft_strncmp(cmd[0], "p", 1) == 0)
// 		{
// 			if (ft_strncmp(cmd[1], "a", 1) == 0)
// 				pa(stacks, ft_false);
// 			else if (ft_strncmp(cmd[1], "b", 1) == 0)
// 				pb(stacks, ft_false);
// 		}
// 		if (ft_strncmp(cmd[0], "r", 1) == 0)
// 		{
			
// 		}
// 	}
// 	else if (ft_strlen(cmd) == 4)
// 	{
// 		if (ft_strncmp(cmd, "rr", 2) == 0)
// 		{
// 			if (ft_strncmp(cmd[2], "a", 1) == 0)
// 				rra(stacks, ft_false);
// 			else if (ft_strncmp(cmd[2], "b", 1) == 0)
// 				rrb(stacks, ft_false);
// 			else if (ft_strncmp(cmd[2], "r", 1) == 0)
// 				rrr(stacks, ft_false);
// 		}
// 	}
// 	else
// 		dbg_printf(err_block, "Error");
// }

void	start_check(t_stacks *stacks)
{
	char			*cmd;
	t_all_actions	*all_actions;

	all_actions = ini_actions();
	cmd = get_next_line(0);
	while (cmd)
	{
		call_action(stacks, cmd, all_actions);
		free(cmd);
		cmd = get_next_line(0);
	}
	free (cmd);
	free(all_actions);
	if (is_sorted(stacks->a) && stack_height(stacks->b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
