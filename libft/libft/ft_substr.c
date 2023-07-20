/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:30:32 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:42:37 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static char	*ft_strncpy(char *dest, const char *src, size_t n);

/*
		Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and it's maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	l;

	l = 0;
	if (s == NULL)
		return (NULL);
	while (s[l] != 0)
		l++;
	if (start >= l)
	{
		sub = (char *)malloc(sizeof(char));
		if (sub == NULL)
			return (NULL);
		*sub = 0;
	}
	else
	{
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (sub == NULL)
			return (NULL);
		ft_strlcpy(sub, s + start, len + 1);
	}
	return (sub);
}
