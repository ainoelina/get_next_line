/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 14:55:41 by avuorio       #+#    #+#                 */
/*   Updated: 2020/12/01 12:04:31 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*null_return(char *string)
{
	free(string);
	return (0);
}

int		minus_return(char *buffer)
{
	free(buffer);
	return (-1);
}

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
	ft_memmove(new, s1, len1);
	ft_memmove(new + len1, s2, len2);
	new[len - 1] = '\0';
	free((char *)s1);
	return (new);
}
