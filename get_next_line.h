/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 14:56:46 by avuorio       #+#    #+#                 */
/*   Updated: 2020/12/01 12:47:04 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		minus_return(char *buffer);
size_t	str_len(char *str);
void	*ft_memmove(void *d, const void *s, size_t len);
char	*join_strings(char *s1, char *s2);
char	*null_return(char *string);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
