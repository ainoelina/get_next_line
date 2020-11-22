/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 12:37:07 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/22 14:57:47 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	string_output(int fd, char **line, char **array)
{
	int		i;
	char	*temp;

	i = 0;
	while (array[fd][i] != '\n' && array[fd][i] != '\0')
		i = i + 1;
	if (array[fd][i] == '\n')
	{
		*line = ft_substr(array[fd], 0, i);
		temp = ft_strdup(array[fd] + i + 1);
		free(array[fd]);
		array[fd] = temp;
		if (array[fd][0] == '\0')
			free(array[fd]);
	}
	else
	{
		*line = ft_strdup(array[fd]);
		free(array[fd]);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*array[FD_SIZE];
	char		*buffer[BUFF_SIZE + 1];
	char		*temp;
	int			reader;

	if (fd < 0 || fd > FD_SIZE || line == NULL)
		return (-1);
	while ((reader = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[reader] = 0;
		if (array[fd] == NULL)
			array[fd] = ft_strdup(buffer);
		temp = ft_strjoin(array[fd], buffer);
		free(array[fd]);
		array[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (reader < 0)
		return (-1);
	if (reader == 0 && array[fd] == NULL)
		return (0);
	return (string_output(fd, line, array));
}

int		main(void)
{
    char    *line;
    int        fd1;
    int        fd2;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
   get_next_line(fd1, &line);
	    printf("%s\n", line);
	get_next_line(fd1, &line);
	    printf("%s\n", line);
	get_next_line(fd1, &line);
	    printf("%s\n", line);
	get_next_line(fd1, &line);
	   printf("%s\n", line);
    return (0);
}
