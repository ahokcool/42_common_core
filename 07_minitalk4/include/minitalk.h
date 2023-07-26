/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:54:01 by astein            #+#    #+#             */
/*   Updated: 2023/07/26 16:45:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft_printf.h"
# include <signal.h>
# include <unistd.h>

# define HEADER_SEP 45
# define HEADER_WIDTH 51
# define CONNECTION_ATTEMPTS 10
# define BIT_0 SIGUSR1
# define BIT_1 SIGUSR2

// FOR CLIENT
// ===============
typedef struct s_msg
{
	pid_t					pid_server;
	char					*msg;
	t_bool					found_server;
	t_bool					transmitting;
}							t_msg;

// FOR SERVER
// ===============
typedef struct s_msg_request
{
	pid_t					pid_client;
	struct s_msg_request	*next;

}							t_msg_request;

typedef struct s_all_msg_requests
{
	t_msg_request			*head;
	t_msg_request			*tail;
}							t_all_msg_requests;

typedef struct s_server
{
	pid_t					cur_pid;
	t_bool					transmitting;
	t_all_msg_requests		*queuing_msgs;
}							t_server;

typedef struct s_server_2
{
	pid_t					queuing_pids[5];
	int						queuing_count;
	int						cur_index;
	pid_t					cur_pid;
}							t_server_2;

void						put_header(char *symbol, char *msg);

#endif