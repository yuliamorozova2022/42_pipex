/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:39:55 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:49:45 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The memmove() function copies n bytes from memory area src to memory
	area dest. The memory areas may overlap: copying takes place as though the
	bytes in src are first copied into a temporary array that does not overlap
	src or dest, and the bytes are then copied from the temporary array to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == NULL && s == NULL)
		return ((void *)dest);
	if (d > s)
	{
		i = (int)(n);
		while (--i >= 0)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return ((void *)dest);
}
