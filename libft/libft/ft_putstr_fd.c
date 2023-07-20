/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:34:18 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/20 15:14:07 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Outputs the string ’s’ to the given file descriptor.
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != 0)
	{
		write(fd, s, 1);
		s++;
	}
}
