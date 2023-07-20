/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:52:17 by ymorozov          #+#    #+#             */
/*   Updated: 2023/02/17 14:02:16 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int n, t_flags *flags)
{
	unsigned long int	buf;
	int					counter;

	buf = n;
	counter = ft_because_of_norms(n, flags);
	if (n < 0)
	{
		write(1, "-", 1);
		buf = -1 * n;
	}
	if (buf == 0)
		write(1, "0", 1);
	else if (buf < 10)
	{
		buf = buf + '0';
		write(1, &buf, 1);
	}
	else
	{
		ft_putnbr((buf - buf % 10) / 10, flags);
		ft_putnbr(buf % 10, flags);
	}
	return (counter);
}

int	ft_because_of_norms(long int n, t_flags *flags)
{
	int	counter;

	if (flags->plus == 0 && flags->space == 0 && flags->hash == 0)
		counter = ft_symb_count(n);
	else
		counter = ft_print_sign_nb(n, flags);
	return (counter);
}

int	ft_symb_count(long int nb)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (++counter);
	if (nb < 0)
		counter++;
	while (nb != 0)
	{
		nb = (nb - nb % 10) / 10;
		counter++;
	}
	return (counter);
}

int	ft_putuint(unsigned int n, t_flags *flags)
{
	int	counter;

	counter = ft_symb_count(n);
	if ((flags->width - counter > 0) && (flags->plus == 1 || flags->space == 1
			|| flags->hash == 1))
		counter += ft_print_space(flags->width - counter, flags);
	ft_struct_init(flags);
	if (n == 0)
		write(1, "0", 1);
	else if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	else
	{
		ft_putuint((n - n % 10) / 10, flags);
		ft_putuint(n % 10, flags);
	}
	return (counter);
}
