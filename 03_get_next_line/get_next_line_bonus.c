/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:01:34 by astein            #+#    #+#             */
/*   Updated: 2023/05/05 17:56:13 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief	This function takes af file descriptor 'fd' and reads it line by
 * 			line. Each time you call it, will return the next line.
 * 			The BUFFE_SIZE is specified in the .h file but can be overwritten
 * 			during compiling with: '-D BUFFER_SIZE=foo'
 * 
 * 			The function DOES remember which fd you passed during the last call.
 * 			So you can use it with multiple files simultaneously.
 * 				
 * @param	fd		The file descriptor from which to read
 * @return	char*
 * 					The next line (including the \n)
 * 					NULL if no next line exists
 */
char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	size_t		len_line;
	size_t		len_cpy;
	t_bool		flg_nl;

	line = NULL;
	len_line = 0;
	len_cpy = 0;
	flg_nl = ft_false;
	if (fd < 0 || fd > FOPEN_MAX || !BUFFER_SIZE)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (zero_str(buffer[fd]));
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		len_nl(line, &len_line, &flg_nl);
		len_nl(buffer[fd], &len_cpy, &flg_nl);
		line = safe_buffer(line, len_line, buffer[fd], len_cpy);
		shift_arr_to_front(buffer[fd], len_cpy);
		if (flg_nl)
			break ;
	}
	return (line);
}

/**
 * @brief	Simple tester
 * 
 * @return	int 
 */
int	main(void)
{
	int		fd_a;
	int		fd_b;
	char	*line_a;
	char	*line_b;

	fd_a = open("a.txt", O_RDONLY);
	fd_b = open("b.txt", O_RDONLY);
	line_a = get_next_line(fd_a);
	line_b = get_next_line(fd_b);
	while (line_a && line_b)
	{
		printf("a: %s", line_a);
		printf("b: %s\n", line_b);
		line_a = get_next_line(fd_a);
		line_b = get_next_line(fd_b);
	}
	close(fd_a);
	close(fd_b);
	free(line_a);
	free(line_b);
	return (0);
}
