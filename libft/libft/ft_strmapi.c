/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:15:51 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:42:07 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		Applies the function ’f’ to each character of the string ’s’, and 
	passing its index as first argument to create a new string (with malloc(3)) 
	resulting from successive applications of ’f’.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (s[i] != 0)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
