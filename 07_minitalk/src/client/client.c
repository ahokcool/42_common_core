/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:29 by astein            #+#    #+#             */
/*   Updated: 2023/07/24 18:44:49 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

void	send_msg(pid_t pid_server, char *msg)
{
	(void) pid_server;
	while (*msg)
	{
		write(1, &msg[0], 1);
		msg++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;

	(void)argv;
	if (argc != 3)
	{
		dbg_printf(err_block, "param error!\nneed: PID MSG\ne.g. 12345 \"Hi\"");
	}
	pid_server = ft_atoi(argv[1]);
	send_msg(pid_server, argv[2]);
	return (0);
}
