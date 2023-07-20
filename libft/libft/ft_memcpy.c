/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:16:31 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/17 16:19:50 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The memcpy() function copies n bytes from memory area src to memory
	area dest. The memory areas must not overlap. Use memmove(3) if the memory
	areas do overlap.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return ((void *)dest);
	if (d == NULL)
		return ((void *)0);
	while (i < (int)n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)dest);
}
