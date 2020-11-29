/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 14:56:46 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/29 15:11:05 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	str_len(char *str);
void	*ft_memmove(void *d, const void *s, size_t len);
char	*join_strings(char *s1, char *s2);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
