/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:25:50 by ymorozov          #+#    #+#             */
/*   Updated: 2023/02/17 12:54:07 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, t_flags *flags)
{
	char	*str;
	int		len;
	int		b;

	str = ft_to_hex(nb);
	b = 0;
	len = ft_strlen(str);
	if (len == 1 && ft_strncmp(str, "0", len) == 0)
		b = 1;
	if (flags->hash == 0 || b == 1)
		len = ft_strlen(str);
	else
		len = ft_strlen(str) + 2;
	if (flags->width - len > 0)
		len += ft_print_space(flags->width - len, flags);
	if (flags->hash == 1 && b == 0)
		write(1, "0x", 2);
	ft_struct_init(flags);
	ft_putstr(str, flags);
	free(str);
	return (len);
}

int	ft_symb_count_hex(unsigned long int nb)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (++counter);
	while (nb != 0)
	{
		nb = (nb - nb % 16) / 16;
		counter++;
	}
	return (counter);
}

int	ft_puthex_cap(unsigned long nb, t_flags *flags)
{
	char	*str;
	int		len;
	int		b;

	str = ft_to_hex(nb);
	b = 0;
	len = -1;
	while (str[++len] != 0)
		str[len] = ft_toupper(str[len]);
	if (len == 1 && ft_strncmp(str, "0", len) == 0)
		b = 1;
	if (flags->hash == 0 || b == 1)
		len = ft_strlen(str);
	else
		len = ft_strlen(str) + 2;
	if (flags->width - len > 0)
		len += ft_print_space(flags->width - len, flags);
	if (flags->hash == 1 && b == 0)
		write(1, "0X", 2);
	ft_struct_init(flags);
	ft_putstr(str, flags);
	free(str);
	return (len);
}

char	*ft_to_hex(unsigned long int nb)
{
	char	*res;
	long	buf;
	long	len;

	len = ft_symb_count_hex(nb);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len--] = 0;
	while (len >= 0)
	{
		buf = nb % 16;
		if (buf < 10)
			res[len--] = 48 + buf;
		else
			res[len--] = 87 + buf;
		nb = nb / 16;
	}
	return (res);
}

int	ft_putptr(unsigned long int nb, t_flags *flags)
{
	int		len;

	if (nb == 0)
		len = 5;
	else if (flags->plus == 1)
		len = ft_symb_count_hex(nb) + 1 + 2;
	else
		len = ft_symb_count_hex(nb) + 2;
	if (flags->width - len > 0)
		len += ft_print_space(flags->width - len, flags);
	else if (flags->width - len <= 0 && flags->space == 1 && flags->plus != 1
		&& nb != 0)
		len += write(1, " ", 1);
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (len);
	}
	if (flags->plus == 1)
		write(1, "+", 1);
	ft_struct_init(flags);
	flags->hash = 1;
	ft_puthex(nb, flags);
	return (len);
}
