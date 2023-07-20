/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:50:05 by ymorozov          #+#    #+#             */
/*   Updated: 2023/03/31 17:02:23 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Write a function that returns a line read from a file descriptor
	return values:
	Read line: correct behavior
	NULL: there is nothing else to read, or an error occurred
*/

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (buf == NULL)
		return (NULL);
	newline = ft_get_line(buf);
	buf = ft_change_buf(buf);
	return (newline);
}

/*
		ft_read() read from file to static buffer until fill find \n or end
	of file or error occurs.
	Returns pointer to static buffer or NULL (error case)
*/

char	*ft_read(int fd, char *buf)
{
	char	*line;
	int		readed;

	readed = 1;
	line = ft_calloc(1, BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	while (readed != 0 && !ft_str_chr(buf, '\n'))
	{
		readed = read(fd, line, BUFFER_SIZE);
		if (readed == -1)
		{
			free(line);
			return (NULL);
		}
		if (readed == 0)
			break ;
		line[BUFFER_SIZE] = 0;
		buf = ft_str_join(buf, line);
		ft_bzero(line, BUFFER_SIZE + 1);
	}
	free(line);
	return (buf);
}

/*
		ft_get_line() create a new line from static buffer.
	Returns pointer to the readed line or NULL (error case)
*/

char	*ft_get_line(char *buf)
{
	int		len;
	char	*str;
	char	*ptr;

	if (*buf == 0)
		return (NULL);
	ptr = ft_str_chr(buf, '\n');
	if (ptr == NULL)
	{
		len = 0;
		while (buf[len] != 0)
			len++;
	}
	else
		len = (ptr - buf) + 1;
	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, buf, len + 1);
	return (str);
}

/*
		ft_change_buf() update a value inside the static buffer after finding
	a line.
	Returns pointer to updated buffer or NULL (error case)
*/

char	*ft_change_buf(char *buf)
{
	char	*new;
	char	*ptr;
	size_t	size;

	size = 0;
	while (buf[size] != 0)
		size++;
	ptr = ft_str_chr(buf, '\n');
	if (ptr == NULL)
	{
		free(buf);
		return (NULL);
	}
	else
		size = size - (ptr - buf);
	new = ft_calloc(size, 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, ptr + 1, size);
	free(buf);
	return (new);
}
