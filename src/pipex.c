/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:20:49 by ymorozov          #+#    #+#             */
/*   Updated: 2023/07/26 11:23:45 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

static int	wait_all(int start, int end);
static int	ft_read_from_pipe(int fd_in, int fd_out);
static int	pipex_skip(t_struct *st);
// static int	extend_func(int *arr, t_cmd	*cur, char **envp, int *fd);

int	pipex_manager(t_struct *st, char **argv, char **envp)
{
	int	n;
	int	res;

	st->fd_read = st->fds[0];
	n = st->first - 1;
	while (++n < st->last)
	{
		res = get_struct(argv[n], envp, st->cur);
		if (res == 1)
			return (1);
		else if (res == 2)
			pipex_skip(st);
		else
		{
			if (pipex(&st->fd_read, st->cur, envp) == 1)
				return (free_struct(st->cur), 1);
			free_struct(st->cur);
		}
	}
	if (res == 2)
		return (close(st->fd_read), 1);
	ft_read_from_pipe(st->fd_read, st->fds[1]);
	if (wait_all(st->first, st->last) == 1)
		return (close(st->fd_read), 1);
	return (close(st->fd_read), 0);
}

// static int	extend_func(int *arr, t_cmd	*cur, char **envp, int *fd)
// {
// 	if (arr[2] == 1)
// 		return (1);
// 	else if (arr[2] == 2)
// 	{
// 		if (pipex_skip(fd) != 0)
// 			return (1); 
// 	}
// 	else
// 	{
// 		if (pipex(fd, cur, envp) == 1)
// 			return (free_struct(cur), 1);
// 		free_struct(cur);
// 	}
// 	return (0);
// }

/* int	pipex_skip(int *fd)
{
	int		fd_rem;
	char	*buf[BUFFER_SIZE];
	int		readed;

	if (*fd == 0)
		return (0);
	fd_rem = open("/dev/null", O_WRONLY);
	readed = 1;
	while (readed != 0)
	{
		readed = read(*fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (perror("Reading"), 1);
		if (readed == 0)
			break ;
		else
		{
			if (write(fd_rem, &buf, readed) <= 0)
				return (perror("Writing"), -1);
		}
	}
	close(fd_rem);
	*fd = STDIN_FILENO;
	return (0);
} */

static int	pipex_skip(t_struct *st)
{
	char	*buf[BUFFER_SIZE];
	int		readed;

	readed = 1;
	while (readed != 0)
	{
		readed = read(st->fd_read, buf, BUFFER_SIZE);
		if (readed == -1)
			return (perror("Reading"), 1);
		if (readed == 0)
			break ;
	}
	return (0);
}

static int	wait_all(int start, int end)
{
	int	status;

	while (start < end)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) == 1)
		{
			if (WEXITSTATUS(status) == 1)
				return (1);
		}
		start++;
	}
	return (0);
}

static int	ft_read_from_pipe(int fd_in, int fd_out)
{
	char	*buf[BUFFER_SIZE];
	int		readed;

	if (dup2(fd_in, STDIN_FILENO) < 0 || dup2(fd_out, STDOUT_FILENO) < 0)
		return (perror("Read from pipe"), 1);
	readed = 1;
	while (readed != 0)
	{
		readed = read(STDIN_FILENO, buf, BUFFER_SIZE);
		if (readed == -1)
			return (perror("Reading"), 1);
		if (readed == 0)
			break ;
		else
		{
			if (write(STDOUT_FILENO, &buf, readed) <= 0)
				return (perror("Writing"), -1);
		}
	}
	return (0);
}
