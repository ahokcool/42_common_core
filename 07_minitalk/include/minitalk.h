/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:54:01 by astein            #+#    #+#             */
/*   Updated: 2023/07/25 13:30:22 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft_printf.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_msg
{
	pid_t	pid_server;
	char	*msg;
}	t_msg;

#endif