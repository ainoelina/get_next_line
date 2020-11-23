/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 10:15:32 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/23 15:09:55 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
