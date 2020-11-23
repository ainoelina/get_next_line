/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testi.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 09:44:41 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/23 09:42:42 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#define MAXCHAR 100
#define BUFF_SIZE 10
#define FD_SIZE 4096

static int	line_len(char **string, char **line)
{
	int		len;
	char	*temporary;

	while ((*string)[len] != '\n' && (*string)[len] != '\0')
		len++;
	if ((*string)[len] == '\n')
		*line = 
}

char	*firstline(char **string, char **line)
{
	char *temp;	
}

int	get_next_line(int fd, char **line)
//{
//	char	buffer[BUFF_SIZE];
//}

int	main(void)
{
	FILE	*fp;
	char	str[MAXCHAR];
	int		fd;
	size_t	nbytes;
	ssize_t	nbytes_read;
	static char *s[FD_SIZE];
	char buff[BUFF_SIZE + 1];
	char *temp;
	int rest;

	while ((rest = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rest] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
	}

	fd = open("testi.txt", O_RDONLY);
	nbytes = sizeof(str);
	nbytes_read = read(fd, str, nbytes);
	printf("file contents are:\n%s\n", str);
	close(fd);
	return (0);
}
