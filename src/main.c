/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:23:03 by ymorozov          #+#    #+#             */
/*   Updated: 2023/07/26 11:05:46 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

static int	ft_open(t_struct *start, char **av, int ac);

int	main(int ac, char **av, char **envp)
{
	t_struct	start;

	if (ac < 5)
		return (ft_putstr_fd("Too few arguments\n", 2), 1);
	start.cur = (t_cmd *)malloc(sizeof(t_cmd));
	if (start.cur == NULL)
		return (1);
	if (ft_open(&start, av, ac) == 1)
		here_doc(start.fds, av);
	start.last = ac - 1;
	if (pipex_manager(&start, av, envp) == 1)
		return (free(start.cur), close_all(start.fds[0], start.fds[1]), 1);
	return (free(start.cur), close_all(start.fds[0], start.fds[1]), 0);
}

static int	ft_open(t_struct *start, char **av, int ac)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			return (ft_putstr_fd("Too few arguments\n", 2), 1);
		start->first = 3;
		start->fds[0] = STDIN_FILENO;
		start->fds[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0666);
		return (1);
	}
	start->first = 2;
	start->fds[0] = open(av[1], O_RDONLY);
	start->fds[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	start->infile_exist = 1;
	if (start->fds[0] < 0)
	{
		start->fds[0] = open("/dev/null", O_RDONLY);
		start->infile_exist = 0;
		ft_printf("%s: %s\n", strerror(errno), av[1]);
	}
	return (0);
}

/*
	for piping process use array of fd (int fd[2]).
	fd[0] always for READING and f[1] for WRITING.
	fork() returns 0 only for child process, -1 for error
*/

int	pipex(int *fd, t_cmd *cmd, char **envp)
{
	int		pipefd[2];
	pid_t	id1;

	if (pipe(pipefd) == -1)
		return (perror("Pipe"), 1);
	id1 = fork();
	if (id1 < 0)
		return (perror("Fork"), 1);
	if (id1 == 0)
	{
		close(pipefd[0]);
		if (dup2(*fd, STDIN_FILENO) < 0 || dup2(pipefd[1], STDOUT_FILENO) < 0)
			return (perror("Child process"), 1);
		execve(cmd->path, cmd->cmd, envp);
	}
	close(pipefd[1]);
	*fd = pipefd[0];
	return (0);
}
