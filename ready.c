

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <fcntl.h>
#define FD_SIZE 4096
#define BUFF_SIZE 10


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t		i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	destination = (char *)dst;
	source = (const char*)src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t lenght;

	lenght = 0;
	while (*s != '\0')
	{
		lenght++;
		s++;
	}
	return (lenght);
}

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		lenght;

	lenght = ft_strlen(s1);
	pointer = malloc(lenght + 1);
	if (pointer == NULL)
	{
		return (NULL);
	}
	ft_memcpy(pointer, s1, lenght);
	pointer[lenght] = '\0';
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
char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
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


char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char    *subs;
    size_t    i;

    if (s == NULL)
        return (NULL);
    subs = ft_strnew(len);
    if (subs == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        subs[i] = s[start + i];
        i++;
    }
    return (subs);
}
void    ft_memdel(void **ap)
{
    if (ap != NULL)
    {
        free(*ap);
        *ap = NULL;
    }
}
void    ft_strdel(char **as)
{
    if (as != NULL && *as != NULL)
        ft_memdel((void**)as);
}

static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;


	int i;
	i = 0;
	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
//		printf("%s - (buffer at this point)\n", buff);
//		printf("%d bytes (read)", ret);
		buff[ret] = '\0';
		if (s[fd] == NULL)
		{
			s[fd] = ft_strdup(buff);
//			printf("\n(at this point the string is null)\n");
		}
		else
		{
//			printf("%d, bytes read\n", ret);
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;

		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	i = 0;
	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
	return (output(s, line, ret, fd));
}

int		main(void)
{
    char    *line;
    int        fd1;
    int        fd2;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
   get_next_line(fd1, &line);
	    printf("%s\n", line);
	get_next_line(fd1, &line);
	    printf("%s\n", line);
	get_next_line(fd1, &line);
	    printf("%s\n", line);
	get_next_line(fd1, &line);
    printf("%s\n", line);
    return (0);
}
  