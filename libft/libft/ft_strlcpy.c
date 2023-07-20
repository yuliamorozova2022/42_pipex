/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:38:00 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/21 11:45:45 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*		The strlcpy() function copy string src to dest. Strlcpy() take the
	full size of the buffer (not just the length) and guarantee to
	NUL-terminate the result (as long as size is larger than 0). Note
	that a byte for the NUL should be included in size. Also note that
	strlcpy() only operate on true ''C'' strings. This means that for
	strlcpy() src must be NUL-terminated.
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	b;
	size_t	i;

	i = 0;
	b = ft_strlen(src);
	if (size == 0 || dest == NULL)
		return (b);
	while (i < (size - 1))
	{
		if (src[i] == 0)
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (b);
}
