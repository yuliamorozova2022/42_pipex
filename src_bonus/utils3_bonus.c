/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:53:23 by ymorozov          #+#    #+#             */
/*   Updated: 2023/04/04 10:23:29 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex_bonus.h"

void	free_struct(t_cmd *cmd)
{
	ft_free(cmd->cmd, size_of_arr(cmd->cmd));
	if (cmd->path != NULL)
		free(cmd->path);
}

t_cmd	*get_struct(char *command, char **envp)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	new->cmd = NULL;
	new->path = NULL;
	new->cmd = ft_split(command, ' ');
	if (new->cmd == NULL)
		return (free(new), NULL);
	new->path = get_path(new->cmd[0], envp);
	if (new->path == NULL)
	{
		free_struct(new);
		free(new);
		return (NULL);
	}
	return (new);
}

void	close_all(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
