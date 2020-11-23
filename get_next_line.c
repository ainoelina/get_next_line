/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 12:37:07 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/23 15:19:41 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	size_t	lenght;
	size_t	i;

	i = 0;
	lenght = ft_strlen(s1);
	pointer = (char *)malloc(sizeof(char) * lenght + 1);
	if (pointer == NULL)
		return (NULL);
	while (pointer[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	dst_index;
	int		i;

	dst_index = ft_strlen(dst);
	length = ft_strlen(src);
	if (dstsize < dst_index)
		return (dstsize + length);
	else
		length = length + dst_index;
	i = 0;
	while (src[i] != '\0' && dst_index + 1 < dstsize)
	{
		dst[dst_index] = src[i];
		dst_index++;
		i++;
	}
	dst[dst_index] = '\0';
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if (dstsize == 0)
		return (ft_strlen(src));
	if (src == 0)
		return (0);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	s1_length;
	size_t	s2_length;
	size_t	string_length;

	if (s1 == NULL)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	string_length = s1_length + s2_length + 1;
	string = (char *)malloc(sizeof(*string) * string_length);
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, s1, s1_length + 1);
	ft_strlcat(string, s2, string_length);
	return (string);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

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
	if (!(ptr = (void *)malloc(size + 1)))
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
