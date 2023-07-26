/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:29 by astein            #+#    #+#             */
/*   Updated: 2023/07/26 17:35:02 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_msg	g_msg;

static void	put_header_client(void)
{
	char	*msg;
	char	*pid_server;
	char	*pid_client;

	pid_server = ft_itoa(g_msg.pid_server);
	pid_client = ft_itoa(getpid());
	msg = ft_strcat_multi(5, "ASTEINS MINITALK CLIENT\n(PID CLIENT: ",
			pid_client, ")\n(PID SERVER: ", pid_server, ")\n");
	put_header("💬", msg);
	free_whatever("ppp", msg, pid_server, pid_client);
}

static void	ini_client(int argc, char **argv)
{
	static int	i;

	if (argc != 3)
		put_exit_header(E_F, "!WRONG PARAMETERS!\n \n./minitalk <MSG> <PID>");
	while (argv[2][i])
	{
		if (!ft_isdigit(argv[2][i]))
			put_exit_header(E_F, "!WRONG SERVER PID!\n(not numeric)");
		i++;
	}
	g_msg.pid_server = ft_atoi(argv[2]);
	if (g_msg.pid_server <= 0)
		put_exit_header(E_F, "!WRONG SERVER PID!\n(pid <= 0)");
	g_msg.msg = argv[1];
	g_msg.found_server = ft_false;
	g_msg.transmitting = ft_false;
	put_header_client();
}

static void	transmit_next_bit(void)
{
	static int	cur_char;
	static int	bit_mask;
	static int	i;

	// usleep(100);
	if (i == 8 && cur_char != 0 && cur_char != 255)
	{
		ft_printf("%c", cur_char);
		cur_char = 0;
		i = 0;
	}
	if (!cur_char)
	{
		if (g_msg.msg[0] == '\0')
		{
			kill(g_msg.pid_server, SIGUSR1);
			return ;
		}
		else
		{
			cur_char = g_msg.msg[0];
			g_msg.msg++;
			bit_mask = 1;
			i = 0;
		}
	}
	if (cur_char & bit_mask)
		kill(g_msg.pid_server, BIT_1);
	else
		kill(g_msg.pid_server, BIT_0);
	bit_mask <<= 1;
	i++;
}

static void	handle_response(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (g_msg.transmitting)
	{
		if (signal == BIT_0)
			transmit_next_bit();
		if (signal == BIT_1)
		{
			write(1, "\n", 1);
			write(1, "\n", 1);
			if (g_msg.msg[0] == '\0')
			{
				put_header("🟢", "!MESSAGE DELIVERED SUCCESSFULLY!");
				exit(EXIT_SUCCESS);
			}
			else
			{
				put_header("❌️", "!COMMUNICATION ERROR!");
				exit(EXIT_FAILURE);
			}
		}
		return ;
	}
	if (!g_msg.found_server && signal == BIT_0)
	{
		g_msg.found_server = 1;
	}
	else if (g_msg.found_server && !g_msg.transmitting && signal == BIT_1)
	{
		g_msg.transmitting = ft_true;
		put_header("🔜", "SERVER IS READY\n(start transmitting...)");
		usleep(500000);
		transmit_next_bit();
	}
}

int	main(int argc, char **argv)
{
	int					i;
	struct sigaction	signal_action;

	ini_client(argc, argv);
	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = handle_response;
	sigaction(BIT_0, &signal_action, NULL);
	sigaction(BIT_1, &signal_action, NULL);
	i = 0;
	while (!g_msg.found_server && i < CONNECTION_ATTEMPTS)
	{
		put_header("🔴", "try to connect to server...");
		kill(g_msg.pid_server, BIT_0);
		sleep(2);
		i++;
	}
	if (i == CONNECTION_ATTEMPTS)
	{
		put_header("❌️", "CONNECTION ERROR\n(server doesnt respond)");
		exit(EXIT_FAILURE);
	}
	put_header("🟠", "server did respond...");
	while (!g_msg.transmitting)
	{
		put_header("🟡", "ping server to get a 'go'...");
		usleep(500);
		kill(g_msg.pid_server, BIT_1);
		sleep(5);
		i++;
	}
	while (1)
		;
	return (0);
}
