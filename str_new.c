/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:15:25 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/23 14:22:08 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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