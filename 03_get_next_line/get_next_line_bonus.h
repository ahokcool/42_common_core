/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:03:02 by astein            #+#    #+#             */
/*   Updated: 2023/05/05 17:45:00 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H ;
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//******************************************************************************
//			Typedefs
//******************************************************************************
typedef enum e_bool
{
	ft_false = 0,
	ft_true = 1
}		t_bool;

//******************************************************************************
//			get_next_line_bonus.c
//******************************************************************************
char	*get_next_line(int fd);

//******************************************************************************
//			get_next_line_utils_bonus.c
//******************************************************************************
void	*zero_str(char *buffer);
void	len_nl(char *str, size_t *len, t_bool *flg_nl);
char	*safe_buffer(char *line, size_t len_line, char *buffer, size_t len_cpy);
void	shift_arr_to_front(char *arr, size_t offset);

#endif
