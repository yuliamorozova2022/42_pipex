/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:21 by ymorozov          #+#    #+#             */
/*   Updated: 2023/02/17 12:26:26 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

• # Prefix 0x to the value when used with the hexadec.conversion character x
• ' ' Print a space before a positive value not printed with the + flag.
• + Display '+'sign preceding positive values, '-'sign for negative values.
*/

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flags	st;
	int		i;
	int		total;

	i = -1;
	total = 0;
	va_start(ap, str);
	while (str[++i] != 0)
	{
		ft_struct_init(&st);
		if (str[i] == '%' && str[i + 1] != 0)
		{
			i += ft_parse_flags(&str[i + 1], &st);
			total += ft_print(&ap, &st, str[i + 1]);
			i++;
		}
		else
			total += ft_putchar(str[i]);
	}
	va_end(ap);
	return (total);
}

int	ft_parse_flags(const char *string, t_flags *flags)
{
	int		i;
	char	*set;

	i = 0;
	set = "cdispxXu%";
	while (ft_strchr(set, string[i]) == NULL)
	{
		if (string[i] == '+')
			flags->plus = 1;
		else if (string[i] == '#')
			flags->hash = 1;
		else if (string[i] == ' ')
			flags->space = 1;
		else if (ft_isdigit(string[i]))
			flags->width = flags->width * 10 + (string[i] - '0');
		else
		{
			i++;
			continue ;
		}
		i++;
	}
	return (i);
}

void	ft_struct_init(t_flags *s)
{
	s->hash = 0;
	s->space = 0;
	s->plus = 0;
	s->width = 0;
}

int	ft_print(va_list *a, t_flags *flags, int c)
{
	int	res;

	res = 0;
	if (c == 'c')
	{
		if (flags->width - 1 > 0)
			res += ft_print_space(flags->width - 1, flags);
		res += ft_putchar(((char) va_arg(*a, int)));
	}
	else if (c == 'd' || c == 'i')
		res += ft_putnbr(va_arg(*a, int), flags);
	else if (c == 's')
		res += ft_putstr(va_arg(*a, char *), flags);
	else if (c == '%')
		res += ft_putchar('%');
	else if (c == 'p')
		res += ft_putptr(va_arg(*a, unsigned long long), flags);
	else if (c == 'u')
		res += ft_putuint(va_arg(*a, unsigned int), flags);
	else if (c == 'x')
		res += ft_puthex(va_arg(*a, unsigned int), flags);
	else if (c == 'X')
		res += ft_puthex_cap(va_arg(*a, unsigned int), flags);
	return (res);
}
