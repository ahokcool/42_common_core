/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:29 by astein            #+#    #+#             */
/*   Updated: 2023/07/24 22:30:11 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

t_bool	waiting;

static void	print_pid(void)
{
	ft_putstr_fd("\n------------------------------\n", 1);
	ft_putstr_fd("    ASTEINS MINITALK CLIENT\n", 1);
	ft_putstr_fd("------------------------------\n\n", 1);
	ft_putstr_fd("server up at (PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(")\n\n", 1);
	ft_putstr_fd("sending message:\n", 1);
}


void	send_char(pid_t pid_server, int c)
{
	int	bit_mask;
	int	i;

	waiting = ft_true;
	bit_mask = 1;
	i = 0;
	// ft_putstr_fd("send char: ", 1);
	// ft_putchar_fd(c, 1);
	// ft_putstr_fd(" (", 1);
	while (i < 8)
	{/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:25:35 by astein            #+#    #+#             */
/*   Updated: 2023/05/09 15:38:12 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_printf.h"

/**
 * @brief	Check if character is a white-space
 * 
 * @param 	c 
 * @return	int
 * 				1 = true
 * 				0 = false
 */
static int	ft_is_space(unsigned char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\f')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\r')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\v')
		return (1);
	else
		return (0);
}

/**

 * @brief This function converts str into int removing ws in the front
 * 
 * @param str string to be converted 
 * @return int converted str
 */
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (ft_is_space(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	result = sign * result;
	return (result);
}

		else
		{
			kill(pid_server, SIGUSR1);
			// ft_putchar_fd('1', 1);
		}
		bit_mask <<= 1;
		i++;
		usleep(100);
	}
	// ft_putstr_fd(")\n", 1);
}

// void	send_msg(pid_t pid_server, char *msg)
// {
// 	(void)pid_server;

// }

void	handler(int signal)
{
	if (signal == SIGUSR1)
	{
		waiting = ft_false;
	}
	if (signal == SIGUSR2)
	{
		ft_printf("\n\nmessage delivered!\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;

	waiting = ft_false;
	print_pid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	if (argc != 3)
		dbg_printf(err_block, "param error!\n[MSG] [PID]\ne.g. \"Hi\" 12345");
	if (ft_strncmp(argv[2], ft_itoa(ft_atoi(argv[2])), ft_strlen(argv[2])) != 0)
		dbg_printf(err_block, "wrong pid!");
	pid_server = ft_atoi(argv[2]);
	if (pid_server <= 0)
		dbg_printf(err_block, "wrong pid!");
	while (argv[1])
	{
		ft_putchar_fd(argv[1][0], 1);
		send_char(pid_server, argv[1][0]);
		argv[1]++;
		while (waiting)
			;
	}
	send_char(pid_server, '\0');
	while (waiting)
			;
	return (0);
}
