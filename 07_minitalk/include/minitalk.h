/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:54:01 by astein            #+#    #+#             */
/*   Updated: 2023/07/25 19:06:25 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft_printf.h"
# include <signal.h>
# include <unistd.h>

# define BIT_0 SIGUSR1
# define BIT_1 SIGUSR2

typedef struct s_msg
{
	pid_t	pid_server;
	char	*msg;
}			t_msg;

#endif