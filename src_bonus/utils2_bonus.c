/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:08:04 by ymorozov          #+#    #+#             */
/*   Updated: 2023/04/04 10:23:38 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex_bonus.h"

static int		ft_string_count(const char *str, char c);
static size_t	ft_symb_in_str(const char *str, char c);
static char		*ft_alloc_str(char **arr, const char *s, int *ind);
static char		*ft_strncpy(char *dest, char *src, unsigned int n);

char	**ft_split_path(char const *s, char c)
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
		k = ft_symb_in_str(s + j, c) + 1;
		if (k > 0)
		{
			res[i] = ft_alloc_str(res, s, (int []){i, j, k});
			if (res[i] == NULL)
				return (NULL);
		}
		j += k;
	}
	res[i] = NULL;
	return (res);
}

static char	*ft_alloc_str(char **arr, const char *s, int *ind)
{
	int	i;
	int	j;
	int	k;

	i = ind[0];
	j = ind[1];
	k = ind[2];
	arr[i] = (char *)malloc(sizeof(char) * (k + 1));
	if (arr[i] == NULL)
	{
		ft_free(arr, i);
		return (NULL);
	}
	ft_strncpy(arr[i], (char *)&s[j], k + 1);
	arr[i][k - 1] = '/';
	return (arr[i]);
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

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	dest[i - 1] = 0;
	return (dest);
}
