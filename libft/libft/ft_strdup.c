/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:08:36 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/17 13:46:50 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*		The strdup() function returns a pointer to a new string which is
	a duplicate of the string s. Memory for the new string is obtained
	with malloc(3), and can be freed with free(3).
*/

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	else
		dest = ft_memcpy(dest, str, len + 1);
	return (dest);
}
