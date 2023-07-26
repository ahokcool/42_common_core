/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:51:32 by astein            #+#    #+#             */
/*   Updated: 2023/07/25 20:25:44 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

static t_server	g_server;

static void	print_header(void)
{
	ft_printf("\n📭 📭 📭 📭 📭 📭 📭 📭 📭 📭 📭 📭\n");
	ft_putstr_fd("📭    ASTEINS MINITALK SERVER\n", 1);
	ft_putstr_fd("📭          (PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(")\n", 1);
	// ft_putstr_fd("      press return (to exit\n", 1));
	ft_printf("📭 📭 📭 📭 📭 📭 📭 📭 📭 📭 📭 📭\n\n");
}

static int	load_next_queuing_msgs(void)
{
	return (0);
}

static void	handler(int signal, siginfo_t *info, void *context)
{
	static int		c;
	static int		bit_shift;
	static t_bool	flg_end_of_msg;

	(void)context;
	if (g_server.cur_pid != 0 && g_server.cur_pid != info->si_pid)
	{
		// MERKE DIR DIE PID FUER SPAETER
		kill(g_server.cur_pid, BIT_0);
		// printf("Merke dir die NUmmer");
		return ;
	}
	if (!g_server.cur_pid)
	{
		// STARTE DIE TRANSMISSION
		g_server.cur_pid = info->si_pid;
		ft_printf("\n📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫\n");
		ft_printf("📫 receiving message from: %i", (int)info->si_pid);
		ft_printf("\n📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫\n\n");
		kill(g_server.cur_pid, BIT_1);
		return ;
	}
	// AKTUELLE TRANSMISSION
	if (signal == BIT_1)
		c |= (1 << bit_shift);
	bit_shift++;
	if (bit_shift == 8 && c == 0)
		flg_end_of_msg = ft_true;
	else
		flg_end_of_msg = ft_false;
	if (bit_shift == 8 && c != 0)
		write(1, &c, 1);
	if (bit_shift == 8)
	{
		bit_shift = 0;
		c = (int)0;
		usleep(100);
	}
	if (flg_end_of_msg)
	{
		ft_printf("\n\n📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬\n");
		ft_printf("📬 end of message from: %i", g_server.cur_pid);
		ft_printf("\n📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬\n\n");
		print_header();
		usleep(500);
		kill(info->si_pid, BIT_1);
		g_server.cur_pid = load_next_queuing_msgs();
	}
	else
	{
		kill(info->si_pid, BIT_0);
	}
}

int	main(void)
{
	struct sigaction	signal_action;

	// g_server = malloc(sizeof(t_server));
	// if (!g_server)
	// 	exit(EXIT_FAILURE);
	print_header();
	signal_action.sa_handler = 0;
	signal_action.sa_flags = SA_SIGINFO | SA_NODEFER;
	signal_action.sa_sigaction = handler;
	sigaction(BIT_0, &signal_action, NULL);
	sigaction(BIT_1, &signal_action, NULL);
	while (1)
		pause();
}
