/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:45 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/19 12:44:59 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The strrchr() function returns a pointer to the last occurrence of the
	character c in the string s.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;
	char	*str;

	buf = NULL;
	str = (char *)s;
	while (*str != 0)
	{
		if (*str == (char)c)
			buf = str;
		str++;
	}
	if (*str == c)
		return (str);
	return (buf);
}
