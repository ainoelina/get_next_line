/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 10:41:09 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/25 12:04:37 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlen(src);
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*destination;
	char	*source;
	size_t	i;
	
	destination = (char *)dst;
	source = (char *)src;
	if (source < destination)
		while (len > 0)
		{
			len--;
			destination[len] = source[len];
		}
	else
	{
		i = 0;
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	strlen1;
	size_t	strlen2;
	size_t	len;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	len = strlen1 + strlen2 + 1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	ft_memmove(new, s1, strlen1);
	ft_memmove(new + strlen1, s2, strlen2);
	new[len - 1] = '\0';
	free((char *)s1);
	return (new);
}
