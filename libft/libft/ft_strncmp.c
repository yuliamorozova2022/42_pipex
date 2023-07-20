/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:39:58 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/17 12:48:15 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The strncmp() function compares the first (at most) n bytes of strings
	s1 and s2. It returns an integer less than, equal to, or greater than 0 if
	s1 is found, respectively, to be less than, to match, or be greater than s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		res;
	size_t	i;

	i = 0;
	res = 0;
	while (i < n && (s1[i] != 0 || s2[i] != 0))
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (res != 0)
			break ;
		i++;
	}
	return (res);
}
