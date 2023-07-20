/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:22:14 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:47:41 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The strjoin function allocates (with malloc(3)) and returns a new string,
	which is the result of the concatenation of ’s1’ and ’s2’.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, l1 + 1);
	ft_strlcpy(str + l1, s2, l2 + 1);
	return (str);
}
