/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:58:12 by ymorozov          #+#    #+#             */
/*   Updated: 2023/07/21 16:03:13 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

void	free_struct(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	ft_free(cmd->cmd, size_of_arr(cmd->cmd));
	if (cmd->path != NULL)
		free(cmd->path);
}

int	get_struct(char *command, char **envp, t_cmd *new)
{
	new->cmd = NULL;
	new->path = NULL;
	new->cmd = ft_split(command, ' ');
	if (new->cmd == NULL)
		return (1);
	new->path = get_path(new->cmd[0], envp);
	if (new->path == NULL)
	{
		// ft_putstr_fd("in get_struct before free_struct\n", 2);	//DELETE
		free_struct(new);
		// ft_putstr_fd("in get_struct after free_struct\n", 2);	//DELETE
		// free(new);
		return (2);
	}
	return (0);
}

void	close_all(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
