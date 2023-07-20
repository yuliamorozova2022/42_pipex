/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:44 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/17 16:07:59 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The memcmp() function compares the first n bytes (each interpreted as
	unsigned char) of the memory areas s1 and s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	int				dif;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	dif = 0;
	if (n == 0)
		return (dif);
	while (i < n)
	{
		dif = str1[i] - str2[i];
		if (dif != 0)
			return (dif);
		i++;
	}
	return (dif);
}
