/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:51:32 by astein            #+#    #+#             */
/*   Updated: 2023/07/24 18:29:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

void	print_pid(void)
{
	ft_putstr_fd("\n------------------------------\n", 1);
	ft_putstr_fd("    ASTEINS MINITALK SERVER\n", 1);
	ft_putstr_fd("------------------------------\n\n", 1);
	ft_putstr_fd("server up at (PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(")\n\n", 1);
	ft_putstr_fd("waiting for messages...\n", 1);
}

void	handler_usr1(int num)
{
	(void)num;
	write(1, "a", 1);
}

void	handler_usr2(int num)
{
	(void)num;
	write(1, "b", 1);
}

int	main(void)
{
	struct sigaction	my_usr1;
	struct sigaction	my_usr2;

	print_pid();
	my_usr1.sa_handler = handler_usr1;
	my_usr2.sa_handler = handler_usr2;
	sigaction(SIGUSR1, &my_usr1, NULL);
	sigaction(SIGUSR2, &my_usr2, NULL);
	while (1)
	{
		pause();
	}
}
/*
	signal
	sigemptyset
	sigaddset
	sigaction
	kill
	getpid
	malloc
	free
	pause
	sleep
	usleep
	exit
	*/