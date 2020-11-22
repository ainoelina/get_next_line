/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 17:09:35 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/22 12:02:56 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define BUFF_SIZE 80

char	*get_file_contents(char **line, int fd)
{
	char	*temp;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	printf("\nsegfault where\n");
	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		printf("\nsegfault where\n");
		buff[ret] = '\0';
		strcpy(temp, buff);
		strdup(temp);
		printf("\nsegfault where2\n");
	}
	return (temp);
}

int	main(int argc, char *argv[])
{
	char	*line;
	int		fd1;
	int		fd2;
	int		ret1;
	int		ret2;
	char	buffer[BUFF_SIZE + 1];
	char	*temp;
	char	*temp2;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	ret1 = read(fd1, buffer, BUFF_SIZE);
	buffer[ret1] = '\0';
	temp = buffer;
	printf("%d bytes read,\n %s (content)", ret1, temp);
	ret2 = read(fd2, buffer, BUFF_SIZE);
	buffer[ret2] = '\0';
	temp2 = buffer;
	printf("\n%d bytes read,\n %s (content)", ret2, temp);
//	get_file_contents(&line, fd1);
//	printf("\n%s, (the file has this in it)", line);
//	get_file_contents(&line, fd2);
//	printf("\n%s, (the file has this in it)", line);
	return (0);
}

