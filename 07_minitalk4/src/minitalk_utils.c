/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:19:46 by astein            #+#    #+#             */
/*   Updated: 2023/07/26 16:40:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	print_n_times(char c, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}

static void	print_borders(char *symbol)
{
	ft_printf("%s", symbol);
	print_n_times(HEADER_SEP, HEADER_WIDTH);
	ft_printf("%s\n", symbol);
}

void	put_header(char *symbol, char *msg)
{
	int		cur_line;
	char	**msg_lines;
	int		count_sep;

	print_borders(symbol);
	msg_lines = ft_split(msg, '\n');
	cur_line = 0;
	while (msg_lines[cur_line])
	{
		count_sep = HEADER_WIDTH - ft_strlen(msg_lines[cur_line]);
		ft_printf("%s", symbol);
		print_n_times(' ', count_sep / 2);
		ft_printf("%s", msg_lines[cur_line]);
		if (count_sep % 2 != 0)
			count_sep++;
		print_n_times(' ', count_sep / 2);
		ft_printf("%s\n", symbol);
		cur_line++;
	}
	free_whatever("a", msg_lines);
	print_borders(symbol);
	ft_printf("\n");
}