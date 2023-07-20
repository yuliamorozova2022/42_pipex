/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:07:17 by ymorozov          #+#    #+#             */
/*   Updated: 2023/03/31 17:01:28 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		The calloc() function allocates memory for an array of nmemb elements of
	size bytes each and returns a pointer to the allocated memory. The memory is
	set to zero. If nmemb or size is 0, then calloc() returns either NULL, or a
	unique pointer value that can later be successfully passed to free().
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size != 0)
	{
		if (nmemb * size / size != nmemb || nmemb * size / nmemb != size)
			return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}
