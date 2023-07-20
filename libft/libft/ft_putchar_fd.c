/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:29:40 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/19 12:33:32 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Outputs the character ’c’ to the given file descriptor.
*/

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
