/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testi.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 09:44:41 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/18 14:30:58 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#define MAXCHAR 100

int	main(void)
{
	FILE	*fp;
	char	str[MAXCHAR];
	int		fd;
	size_t	nbytes;
	ssize_t	nbytes_read;

	fd = open("testi.txt", O_RDONLY);
	nbytes = sizeof(str);
	nbytes_read = read(fd, str, nbytes);
	printf("file contents are:\n%s\n", str);
	close(fd);
	return (0);
}
