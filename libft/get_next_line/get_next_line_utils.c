/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:27:33 by ymorozov          #+#    #+#             */
/*   Updated: 2023/03/31 17:02:47 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_chr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size != 0)
	{
		if (nmemb * size / size != nmemb || nmemb * size / nmemb != size)
			return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

char	*ft_str_join(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;

	l1 = 0;
	if (s1 == NULL)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		if (s1 == NULL)
			return (NULL);
	}
	while (s1[l1] != 0)
		l1++;
	l2 = 0;
	if (s2 == NULL)
		return (NULL);
	while (s2[l2] != 0)
		l2++;
	str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, l1 + 1);
	ft_strlcpy(str + l1, s2, l2 + 1);
	free(s1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	b;
	size_t	i;

	i = 0;
	b = 0;
	while (src[b] != 0)
		b++;
	if (size == 0 || dest == NULL)
		return (b);
	while (i < (size - 1))
	{
		if (src[i] == 0)
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (b);
}
