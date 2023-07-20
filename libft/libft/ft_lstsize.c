/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:56:17 by ymorozov          #+#    #+#             */
/*   Updated: 2023/01/20 13:24:18 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Counts the number of nodes in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
