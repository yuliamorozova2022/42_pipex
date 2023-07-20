/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:13:59 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/17 15:55:00 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*		The strlcat() function concatenate strings. Strlcat() take the full size
	of the buffer (not just the length) and guarantee to NUL-terminate the
	result (as long as there is at least one byte free in dst). Note that
	a byte for the NUL should be included in size. Also note that strlcat()
	only operate on true ''C'' strings. This means that for strlcat() both
	src and dst must be NUL-terminated.
*/

/*
	find end of dest string:
		while (n-- != 0 && *d != 0)
			d++;
	find length of dest string:
		len = d - dest;
	find free bytes in dest:
		n = size - len;
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	n;
	size_t	ret;
	char	*d;

	d = dest;
	n = size;
	while (n-- != 0 && *d != 0)
		d++;
	len = d - dest;
	n = size - len;
	ret = len + ft_strlen(src);
	if (n == 0)
		return (ret);
	while (*src != 0)
	{
		if (n != 1)
		{
			*d++ = *src;
			n--;
		}
		src++;
	}
	*d = 0;
	return (ret);
}
