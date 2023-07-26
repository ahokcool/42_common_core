/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:29 by astein            #+#    #+#             */
/*   Updated: 2023/07/25 20:18:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

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
	g_msg.transmitting = ft_false;
	// g_msg.msg = "Ho";
}

static void	transmit(void)
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
		// write(1,"2",1);
		kill(g_msg.pid_server, SIGUSR2);
	}
	else
	{
		// write(1,"1",1);
		kill(g_msg.pid_server, SIGUSR1);
	}
	bit_mask <<= 1;
	// ft_printf("send char: %c | bit %i\n", cur_char, i);
	usleep(100);
	i++;
}

static void	handle_response(int signal)
{
	if (g_msg.transmitting)
	{
		if (signal == BIT_0)
			transmit();
		else if (signal == SIGUSR2)
		{
			ft_printf("\n---\nmessage delivered successfully!\n");
			// free(g_msg.msg);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		g_msg.found_server = ft_true;
		ft_printf("\n---\nserver did respond\n");
		if (signal == BIT_0)
		{
			ft_printf("\n🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨\n");
			ft_printf("\n---\n🚨 server is busy! start when server is ready\n");
			ft_printf("\n🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨 🚨\n");
		}
		if (signal == BIT_1)
		{
			g_msg.transmitting = ft_true;
			ft_printf("\n---\nstart transmission\n");
			usleep(500);
			transmit();
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	// g_msg = malloc(sizeof(t_msg));
	// if (!g_msg)
	// 	exit(EXIT_FAILURE);
	ini_client(argc, argv);
	print_header();
	i = 0;
	while (!g_msg.found_server && i < CONNECTION_ATTEMPTS)
	{
		ft_printf("CONNECTION ATTEMPT %i", i);
		kill(g_msg.pid_server, BIT_0);
		usleep(500);
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
