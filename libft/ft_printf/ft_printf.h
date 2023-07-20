/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:29:02 by ymorozov          #+#    #+#             */
/*   Updated: 2023/03/21 11:11:10 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct s_flags
{
	int	hash;
	int	space;
	int	plus;
	int	width;
}				t_flags;

int		ft_printf(const char *str, ...);
int		ft_parse_flags(const char *string, t_flags *flags);
void	ft_struct_init(t_flags *s);
int		ft_print(va_list *a, t_flags *flags, int c);
int		ft_print_space(int nb, t_flags *flags);
int		ft_print_sign_nb(long int nb, t_flags *flags);
int		ft_putchar(int c);
int		ft_putstr(char *str, t_flags *flags);
int		ft_putnbr(long int n, t_flags *flags);
int		ft_symb_count(long int nb);
int		ft_symb_count_hex(unsigned long int nb);
int		ft_putuint(unsigned int n, t_flags *flags);
int		ft_puthex(unsigned long nb, t_flags *flags);
int		ft_puthex_cap(unsigned long nb, t_flags *flags);
char	*ft_to_hex(unsigned long int nb);
int		ft_putptr(unsigned long int nb, t_flags *flags);
int		ft_because_of_norms(long int n, t_flags *flags);

#endif
