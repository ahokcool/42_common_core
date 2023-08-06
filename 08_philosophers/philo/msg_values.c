/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:41:41 by astein            #+#    #+#             */
/*   Updated: 2023/08/06 06:58:54 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static const char	*get_msg_with_clr(int msg_id)
{
	if (msg_id == MSG_ID_FORK)
		return ("\033[0;31mhas taken a fork\033[0m");
	if (msg_id == MSG_ID_FORK_DROP)
		return ("\033[0;32mhas dropped a fork\033[0m");
	if (msg_id == MSG_ID_EAT)
		return ("\033[0;33mis eating\033[0m");
	if (msg_id == MSG_ID_FINISHED_EAT)
		return ("\033[0;34mhas finished eating\033[0m");
	if (msg_id == MSG_ID_SLEEP)
		return ("\033[0;36mis sleeping\033[0m");
	if (msg_id == MSG_ID_THINK)
		return ("\033[0;35mis thinking\033[0m");
	if (msg_id == MSG_ID_DIED)
		return ("\033[0;31mdied\033[0m");
	return("");
}

static const char	*get_msg_without_clr(int msg_id)
{
	if (msg_id == MSG_ID_FORK)
		return ("has taken a fork");
	if (msg_id == MSG_ID_FORK_DROP)
		return ("has dropped a fork");
	if (msg_id == MSG_ID_EAT)
		return ("is eating");
	if (msg_id == MSG_ID_SLEEP)
		return ("is sleeping");
	if (msg_id == MSG_ID_THINK)
		return ("is thinking");
	if (msg_id == MSG_ID_DIED)
		return ("died");
	return("");
}

const char	*get_msg(int msg_id)
{
	if (PUT_MORE_INFOS)
		return (get_msg_with_clr(msg_id));
	else
		return (get_msg_without_clr(msg_id));
}
