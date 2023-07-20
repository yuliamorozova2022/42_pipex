/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:22:53 by ymorozov          #+#    #+#             */
/*   Updated: 2023/04/04 10:24:01 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex_bonus.h"

static int	read_from_input(int *pipefd, char *stop);

void	here_doc(int *fd, char **av)
{
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("Pipe");
		return ;
	}
	read_from_input(pipefd, av[2]);
	close(pipefd[1]);
	fd[0] = pipefd[0];
}

static int	read_from_input(int *pipefd, char *stop)
{
	char	*line;

	while (1)
	{
		ft_printf("heredoc> ");
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			return (1);
		if (ft_strncmp(line, stop, ft_strlen(stop)) == 0)
		{
			free(line);
			return (0);
		}
		write(pipefd[1], line, ft_strlen(line));
		free(line);
	}
}
