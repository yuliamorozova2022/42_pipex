/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:48:33 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:38:57 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Outputs the integer ’n’ to the given file descriptor.
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	buf;

	buf = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		buf = -1 * n;
	}
	if (buf == 0)
		write(fd, "0", 1);
	else if (buf < 10)
	{
		buf = buf + '0';
		write(fd, &buf, 1);
	}
	else
	{
		ft_putnbr_fd((buf - buf % 10) / 10, fd);
		ft_putnbr_fd((buf % 10), fd);
	}
}
