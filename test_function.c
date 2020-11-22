/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_function.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 09:55:07 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/21 14:29:06 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include "get_next_line.h"
#define BUFFER_SIZE 10

int	get_next_line(int fd, char **line)
{
	static char	*string;
	char		*temp;
	int			buffer[BUFFER_SIZE + 1];
	int			reader;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((reader = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (string[fd] == NULL)
			string[fd] == ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(string[fd], buffer);
			free(string[fd]);
			string[fd] = temp;
		}
		if (ft_strchr(string[fd], '\n'))
			break ;
	}
}

int	main(int argc, char *argv[])
{
	char	*line;
	int		fd1;
	int		fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	return (0);
}