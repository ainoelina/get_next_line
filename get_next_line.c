/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl_test.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 12:37:07 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/24 10:43:09 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	substring = malloc(len + 1);
	if (!substring)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			substring[j] = s[i];
			j++;
		}
		i++;
	}
	substring[j] = '\0';
	return (substring);
}

char	*str_new(size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	else
	{
		while (i < size + 1)
		{
			((char *)ptr)[i] = '\0';
			i++;
		}
	}
	return ((char *)ptr);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

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
		ft_strdel(&array[fd]);
		array[fd] = temp;
		if (array[fd][0] == '\0')
			ft_strdel(&array[fd]);
	}
	else
	{
		*line = ft_strdup(array[fd]);
		ft_strdel(&array[fd]);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*array[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			reader;

	if (fd < 0 || fd > FD_SIZE || line == NULL)
		return (-1);
	while ((reader = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (array[fd] == NULL)
			array[fd] = str_new(1);
		temp = ft_strjoin(array[fd], buffer);
		ft_strdel(&array[fd]);
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