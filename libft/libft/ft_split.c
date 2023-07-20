/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:09:27 by ymorozov          #+#    #+#             */
/*   Updated: 2023/03/30 10:05:27 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_string_count(const char *str, char c);
static size_t	ft_symb_in_str(const char *str, char c);
static char		**ft_free(char **array, size_t n);

/*
		Allocates (with malloc(3)) and returns an array of strings obtained by 
	splitting ’s’ using the character ’c’ as a delimiter. The array must end
	with a NULL pointer.
*/

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (ft_string_count(s, c) + 1));
	if (res == NULL)
		return (res);
	while (++i < ft_string_count(s, c))
	{
		while (s[j] == c)
			j++;
		k = ft_symb_in_str(s + j, c);
		if (k > 0)
		{
			res[i] = ft_substr(s + j, 0, k);
			if (!res[i])
				return (ft_free(res, i));
		}
		j += k;
	}
	res[i] = 0;
	return (res);
}

static int	ft_string_count(const char *str, char c)
{
	size_t	str_count;
	size_t	i;

	i = 0;
	str_count = 0;
	if (str[i] == 0)
		return (str_count);
	while (str[i] != 0)
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i])
			i++;
		if (str[i - 1] != c)
			str_count++;
	}
	return (str_count);
}

static size_t	ft_symb_in_str(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			break ;
		else
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **array, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
