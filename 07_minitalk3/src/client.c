/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:29 by astein            #+#    #+#             */
/*   Updated: 2023/07/26 03:39:35 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_msg	g_msg;

static void	print_header(void)
{
	ft_putstr_fd("\n------------------------------\n", 1);
	ft_putstr_fd("    ASTEINS MINITALK CLIENT\n", 1);
	ft_putstr_fd("      (PID CLIENT: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(")\n", 1);
	ft_putstr_fd("      (PID SERVER: ", 1);
	ft_putnbr_fd(g_msg.pid_server, 1);
	ft_putstr_fd(")\n", 1);
	ft_putstr_fd("------------------------------\n\n", 1);
	ft_putstr_fd("start transmission...\n---\n", 1);
}

static void	ini_client(int argc, char **argv)
{
	char	*pid_server_str;
	int		i;

	if (argc != 3)
		dbg_printf(err_block, "param error!\n[MSG] [PID]\ne.g. \"Hi\" 12345");
	i = 0;
	while (argv[2][i])
	{
		if (!ft_isdigit(argv[2][i]))
			dbg_printf(err_block, "wrong pid! (not numeric)");
		i++;
	}
	pid_server_str = ft_itoa(ft_atoi(argv[2]));
	if (ft_strncmp(argv[2], pid_server_str, ft_strlen(argv[2]) != 0))
		dbg_printf(err_block, "wrong pid! (not numeric)");
	free(pid_server_str);
	g_msg.pid_server = ft_atoi(argv[2]);
	if (g_msg.pid_server <= 0)
	{
		// free(g_msg);
		dbg_printf(err_block, "wrong pid! (pid <= 0)");
	}
	// char	test[2];
	// test[0] = 255;
	// test[1] = 0;
	// g_msg.msg = ft_strcat_multi(2, test, argv[1]);
	
	g_msg.msg = argv[1];
	g_msg.found_server = ft_false;
	// g_msg.msg = "Ho";
}

static void	transmit_next_bit(void)
{
	static int	cur_char;
	static int	bit_mask;
	static int	i;

	
	
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
			// ft_printf("send null char | bit %i\n", i);
			kill(g_msg.pid_server, SIGUSR1);
			return ;
		}
		else
		{
			cur_char = g_msg.msg[0];
			// write(1,"\n>",1);
			// write(1, &cur_char, 1);
			// write(1,"<",1);
			g_msg.msg++;
			bit_mask = 1;
			i = 0;
		}
	}

	// usleep(100);
	if (cur_char & bit_mask)
	{
		write(1,"1",1);
		kill(g_msg.pid_server, BIT_1);
	}
	else
	{
		write(1,"0",1);
		kill(g_msg.pid_server, BIT_0);
	}
	bit_mask <<= 1;
	// ft_printf("send char: %c | bit %i\n", cur_char, i);
	usleep(100);
	i++;
}

static void	handle_response(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	
	if (!g_msg.found_server)
	{
		g_msg.found_server = 1;
		ft_printf("\n---\nserver did respond - waiting for server to start transmission...\n");
		// sleep(5);
		transmit_next_bit();
	}
	else
	{
		if (signal == BIT_0)
			transmit_next_bit();
		if (signal == BIT_1)
		{
			ft_printf("\n---\nmessage delivered successfully!\n");
			// free(g_msg.msg);
			exit(EXIT_SUCCESS);
		}		
	}
}

int	main(int argc, char **argv)
{
	int	i;

	struct sigaction	signal_action;

	create_header("=", "No WAY");
	create_header("📌", "No WAY");
	create_header("🖨️", "No WAY");
	create_header("📱", "No WA");
	ini_client(argc, argv);
	// signal_action.sa_handler = 0;
	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = handle_response;
	sigaction(BIT_0, &signal_action, NULL);
	sigaction(BIT_1, &signal_action, NULL);
	// signal(SIGUSR1, handle_response);
	// signal(SIGUSR2, handle_response);
	print_header();
	i = 0;
	while (!g_msg.found_server && i < CONNECTION_ATTEMPTS)
	{
		create_header("🔗", "setting\nup\nconnection...");
		// ft_printf("CONNECTION ATTEMPT (%i|%i)\n", i+1, CONNECTION_ATTEMPTS);
		kill(g_msg.pid_server, BIT_0);
		usleep(500000);
		i++;
	}
	if (i == CONNECTION_ATTEMPTS)
	{
		ft_printf("CONNECTION ERROR - SERVER DOESNT RESPOND");
		exit(EXIT_FAILURE);
	}
	while (1)
		;
	return (0);
}
