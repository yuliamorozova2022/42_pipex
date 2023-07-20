/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:28:23 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:44:36 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The strnstr function locates the 1st occurrence of the null-terminated
	string little in the string big, where not more than len characters are 
	searched. Characters that appear after a ‘\0’ character are not searched.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	if (big == NULL || len == 0)
		return (0);
	i = 0;
	while (big[i] != 0 && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && (i + j < len)
			&& (big[i + j] == little[j]))
			j++;
		if (little[j] == 0)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
