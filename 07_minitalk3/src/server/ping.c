/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:26:14 by astein            #+#    #+#             */
/*   Updated: 2023/07/24 22:41:08 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void	handler(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1)
	{
		write(1, "1", 1);
		kill(info->si_pid, SIGUSR1);
	}
}

int main()
{
	struct sigaction	signal_action;

	signal_action.sa_handler = 0;
	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = handler;

	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);

	printf("pid: %i\n",getpid());
	while (1)
		;



}
