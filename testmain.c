/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 12:39:41 by avuorio       #+#    #+#                 */
/*   Updated: 2020/11/29 12:41:41 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd1;
	int fd2;
    int ret;
    int line;
    char *buff;
    line = 0;

    fd1 = open("test1.txt", O_RDONLY);
    while ((ret = get_next_line(fd1, &buff)) > 0)
    {
        printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
        free(buff);
    }
    printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
    if (ret == -1)
        printf("-----------\nError\n");
    else if (ret == 0)
        printf("-----------\nEnd of file\n");
    close(fd1);

    fd2 = open("test2.txt", O_RDONLY);
    while ((ret = get_next_line(fd2, &buff)) > 0)
    {
        printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
        free(buff);
    }
    printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
    if (ret == -1)
        printf("-----------\nError\n");
    else if (ret == 0)
        printf("-----------\nEnd of file\n");
    close(fd2);
    return (0);
}