/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:09:28 by ymorozov          #+#    #+#             */
/*   Updated: 2023/07/25 16:45:58 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

char	*get_path(char *command, char **envp)
{
	char	*tmp;
	char	**str_arr;
	int		i;

	i = -1;
	str_arr = NULL;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			if (tmp == NULL)
				return (NULL);
			str_arr = ft_split_path(tmp, ':');
			free(tmp);
			if (str_arr == NULL)
				return (NULL);
			break ;
		}
	}
	tmp = find_path(command, str_arr);
	ft_free(str_arr, size_of_arr(str_arr));
	return (tmp);
}

int	size_of_arr(char **array)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (array == NULL)
		return (counter);
	while (array[i] != NULL)
	{
		counter++;
		i++;
	}
	return (counter);
}

char	*find_path(char *cmd, char **array)
{
	int		i;
	char	*res;

	i = 0;
	while (array[i] != NULL)
	{
		res = ft_strjoin(array[i], cmd);
		if (res == NULL)
			return (NULL);
		if (access(res, X_OK) == 0)
			return (res);
		i++;
		free(res);
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

void	ft_free(char **array, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
