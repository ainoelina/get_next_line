#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 10

size_t	str_len(char *str)
{
	size_t i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *d, const void *s, size_t len)
{
	char	*dest;
	char	*src;
	size_t	i;

	dest = (char *)d;
	src = (char *)s;
	if (dest > src)
		while (len > 0)
		{
			len--;
			dest[len] = src[len];
		}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (d);
}

char	*join_strings(char *s1, char *s2)
{
	size_t		len1;
	size_t		len2;
	size_t		len;
	char		*new;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = str_len(s1);
	len2 = str_len(s2);
	len = len1 + len2 + 1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	ft_memmove(new, s1, len1);
	ft_memmove(new + len1, s2, len2);
	new[len - 1] = '\0';
	free((char *)s1);
	return (new);
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
	{
		free(string);
		return (0);
	}
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
	if (!buffer)
		return (-1);
	while (!contains_newline(rest) && reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		rest = join_strings(rest, buffer);
		if (!join_strings)
			return (-1);
	}
	free(buffer);
	*line = create_line(rest);
	rest = create_rest(rest);
	if (reader == 0)
		return (0);
	return (1);
}