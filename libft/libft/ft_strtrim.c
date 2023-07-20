/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:49:12 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:42:26 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		Allocates (with malloc(3)) and returns a copy of ’s1’ with the 
	characters specified in ’set’ removed from the beginning and the end 
	of the string.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = -1;
	j = -1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (++i <= len / 2)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
	}
	while (++j < len / 2)
	{
		if (ft_strchr(set, s1[len - j - 1]) == NULL)
			break ;
	}
	res = ft_substr(s1, i, len - i - j);
	if (res == NULL)
		return (NULL);
	return (res);
}
