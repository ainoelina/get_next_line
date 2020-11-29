/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 12:37:07 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/29 12:42:06 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_array(char *array)
{
	char	*new_array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!array)
		return (0);
	while (array[i] && array[i] != '\n')
		i++;
	if (!array[i])
	{
		free(array);
		return (0);
	}
	new_array = malloc(sizeof(char) * ((ft_strlen(array) - i) + 1));
	if (!new_array)
		return (0);
	i++;
	while (array[i] != '\0')
	{
		new_array[j] = array[i];
		j++;
		i++;
	}
	new_array[j] = '\0';
	free(array);
	return (new_array);
}

char	*create_line(char *string)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (0);
	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
	{
		new_line[i] = string[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int		is_newline(char *string)
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

int				get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;
	int			reader;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	reader = 1;
	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
		return (-1);
	while (!is_newline(str) && reader > 0)
	{
		reader = read(fd, buffer, BUFF_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		str = ft_strjoin(str, buffer);
	}
//	free(buffer);
	*line = create_line(str);
	str = create_array(str);
	if (reader == 0)
		return (0);
	return (1);
}
