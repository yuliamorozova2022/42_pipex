/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:15:27 by ymorozov          #+#    #+#             */
/*   Updated: 2023/02/17 12:58:20 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_space(int nb, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->space == 1 || flags->plus == 1 || flags->hash == 1)
	{
		if (nb <= 0 && flags->space == 1)
		{
			write(1, " ", 1);
			i++;
		}
		while (i < nb)
		{
			write(1, " ", 1);
			i++;
		}
		flags->space = 0;
	}
	return (i);
}

int	ft_print_sign_nb(long int nb, t_flags *flags)
{
	int	len;

	len = ft_symb_count(nb);
	if (nb >= 0 && flags->plus == 1)
		len++;
	if (flags->plus == 1)
	{
		if (flags->width - len > 0)
			len += ft_print_space(flags->width - len, flags);
		if (nb >= 0)
			write(1, "+", 1);
		ft_struct_init(flags);
	}
	else if (flags->space == 1 || flags->hash == 1)
	{
		if (flags->width - len > 0)
			len += ft_print_space(flags->width - len, flags);
		else if (nb >= 0 && flags->space == 1)
			len += write(1, " ", 1);
		ft_struct_init(flags);
	}
	else
		len = 0;
	return (len);
}

int	ft_putstr(char *str, t_flags *flags)
{
	int	counter;
	int	len;

	counter = 0;
	if (str == NULL)
		len = 6;
	else
		len = ft_strlen(str);
	if (flags->width - len > 0)
		counter += ft_print_space(flags->width - len, flags);
	len = 0;
	if (str == NULL)
		counter += write(1, "(null)", 6);
	else
	{
		while (str[len] != 0)
			counter += ft_putchar(str[len++]);
	}
	return (counter);
}
