/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 13:28:24 by avuorio       #+#    #+#                 */
/*   Updated: 2020/12/01 11:27:22 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*null_return(char *string)
{
	free(string);
	return (0);
}

char	*create_rest(char *string)
{
	char	*remain;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (string == NULL)
		return (NULL);
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == 0)
		return (null_return(string));
	remain = malloc(sizeof(char) * ((str_len(string) - i) + 1));
	if (!remain)
		return (0);
	i++;
	while (string[i] != '\0')
	{
		remain[j] = string[i];
		j++;
		i++;
	}
	remain[j] = '\0';
	free(string);
	return (remain);
}

char	*create_line(char *string)
{
	char	*line;
	size_t	i;

	if (string == NULL)
		return (NULL);
	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
	{
		line[i] = string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int		contains_newline(char *string)
{
	int i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *rest;
	char		*buffer;
	int			reader;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	reader = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	while (!contains_newline(rest) && reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (-1);
		buffer[reader] = '\0';
		rest = join_strings(rest, buffer);
		if (!rest)
			return (-1);
	}
	free(buffer);
	*line = create_line(rest);
	rest = create_rest(rest);
	if (reader == 0)
		return (0);
	return (1);
}
