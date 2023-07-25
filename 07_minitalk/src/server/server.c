/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:51:32 by astein            #+#    #+#             */
/*   Updated: 2023/07/25 15:24:44 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

static void	print_header(void)
{
	ft_putstr_fd("\n------------------------------\n", 1);
	ft_putstr_fd("    ASTEINS MINITALK SERVER\n", 1);
	ft_putstr_fd("          (PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(")\n\n", 1);
	ft_putstr_fd("      press return to exit\n", 1);
	ft_putstr_fd("------------------------------\n\n", 1);
}

static void	handler(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	bit_shift;

	(void)context;
	if (signal == SIGUSR2)
		c |= (1 << bit_shift);
	bit_shift++;
	if (bit_shift == 8 && c == '\0')
		kill(info->si_pid, SIGUSR2);
	else if (bit_shift == 8)
	{
		write(1, &c, 1);
		bit_shift = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signal_action;

	print_header();
	signal_action.sa_handler = 0;
	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = handler;
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	while(1)
	;
	// getchar();
}
