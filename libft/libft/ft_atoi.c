/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:34:14 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:50:47 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c);

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_is_space(str[i]))
		i++;
	if ((str[i]) == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	ft_is_space(char c)
{
	if ((c >= '\b' && c <= '\r') || c == ' ')
		return (1);
	else
		return (0);
}
