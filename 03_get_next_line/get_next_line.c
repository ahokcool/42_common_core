/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:41:47 by astein            #+#    #+#             */
/*   Updated: 2023/05/05 17:55:38 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief	This function takes af file descriptor 'fd' and reads it line by
 * 			line. Each time you call it, will return the next line.
 * 			The BUFFE_SIZE is specified in the .h file but can be overwritten
 * 			during compiling with: '-D BUFFER_SIZE=foo'
 * 
 * 			Note: The function DOES NOT remember which fd you passed during the
 * 				last call. So always use one fd until the end (return NULL)
 * 				before starting with a new fd. Or use the 'get_next_line'
 *				function in the _bonus.c file!
 * 				
 * @param	fd		The file descriptor from which to read
 * @return	char*
 * 					The next line (including the \n)
 * 					NULL if no next line exists
 */
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
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
		return (zero_str(buffer));
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		len_nl(line, &len_line, &flg_nl);
		len_nl(buffer, &len_cpy, &flg_nl);
		line = safe_buffer(line, len_line, buffer, len_cpy);
		shift_arr_to_front(buffer, len_cpy);
		if (flg_nl)
			break ;
	}
	return (line);
}

/**
 * @brief	Simple tester
 * 
 * @return int 
 */
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("a.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}
