/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:53:34 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/17 16:07:39 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The memchr() function scans the initial n bytes of the memory area
	pointed to by s for the first instance of c. Both c and the bytes of the
	memory area pointed to by s are interpreted as unsigned char.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
