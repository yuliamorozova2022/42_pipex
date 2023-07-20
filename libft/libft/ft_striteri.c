/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:24:01 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:41:49 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		Applies the function ’f’ on each character of the string passed as 
	argument, passing its index as first argument. Each character is passed by 
	address to ’f’ to be modified if necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != 0)
	{
		(*f)(i, s + i);
		i++;
	}
}
