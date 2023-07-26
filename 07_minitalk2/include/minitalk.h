/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:54:01 by astein            #+#    #+#             */
/*   Updated: 2023/07/25 20:18:33 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft_printf.h"
# include <signal.h>
# include <unistd.h>

# define CONNECTION_ATTEMPTS 50
# define BIT_0 SIGUSR1
# define BIT_1 SIGUSR2

typedef struct s_msg
{
	pid_t					pid_server;
	char					*msg;
	t_bool					found_server;
	t_bool					transmitting;
}							t_msg;

typedef struct s_msg_request
{
	pid_t					pid_client;
	struct s_msg_request	*next;
}							t_msg_request;

typedef struct s_server
{
	pid_t					cur_pid;
	t_msg_request			*queuing_msgs;
}							t_server;

#endif