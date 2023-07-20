/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:38:39 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:38:45 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_parse(char *arr, size_t n);
static void		ft_swapchr(char *arr);

/*
		Allocates (with malloc(3)) and returns a string representing the integer
	received as an argument. Negative numbers must be handled
*/

//11 - max number of signs for integer (including '-')

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	sign = (n < 0);
	res = (char *)ft_calloc((11 + sign), sizeof(char));
	if (!res)
		return (NULL);
	if (n == -2147483648)
	{
		len = ft_parse(res, 2147483647);
		res[0] = '8';
		res[10] = '-';
	}
	else
	{
		if (sign)
			n *= -1;
		len = ft_parse(res, n);
		if (sign)
			res[len] = '-';
	}
	ft_swapchr(res);
	return (res);
}

static size_t	ft_parse(char *arr, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
	{
		arr[i] = n + '0';
		i++;
	}
	while (n != 0)
	{
		arr[i] = n % 10 + '0';
		n = (n - (n % 10)) / 10;
		i++;
	}
	return (i);
}

static void	ft_swapchr(char *arr)
{
	char	buff;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (arr[len] != 0)
		len++;
	while (i < len / 2)
	{
		buff = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = buff;
		i++;
	}
}
