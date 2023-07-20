/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:58:50 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/23 11:42:41 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		Takes as a parameter a node and frees the memory of the node’s content 
	using the function ’del’ given as a parameter and free the node. The memory
	of ’next’ must not be freed.

	lst: The node to free.
	del: The address of the function used to delete the content.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	if (del != NULL)
		(*del)(lst->content);
	free(lst);
}
