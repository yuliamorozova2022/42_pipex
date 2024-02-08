/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:23:03 by ymorozov          #+#    #+#             */
/*   Updated: 2023/04/04 10:23:58 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex_bonus.h"

static int	ft_open(int *fds, int *i, char **av, int ac);

int	main(int ac, char **av, char **envp)
{
	int	fds[2];
	int	i;

	if (ac < 5)
		return (ft_putstr_fd("Too few arguments\n", 2), 1);
	if (ft_open(fds, &i, av, ac) == 1)
		return (1);
	if (fds[0] == STDIN_FILENO)
		here_doc(fds, av);
	if (pipex_manager((int []){i, ac - 1}, av, envp, fds) == 1)
		return (1);
	return (close_all(fds[0], fds[1]), 0);
}

static int	ft_open(int *fds, int *i, char **av, int ac)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			return (ft_putstr_fd("Too few arguments\n", 2), 1);
		*i = 3;
		fds[0] = STDIN_FILENO;
		fds[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0666);
		if (fds[1] < 0)
			return (ft_printf("%s: %s\n", strerror(errno), av[ac - 1]), 1);
		return (0);
	}
	*i = 2;
	fds[0] = open(av[1], O_RDONLY);
	fds[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fds[0] < 0)
	{
		close(fds[1]);
		return (ft_printf("%s: %s\n", strerror(errno), av[1]), 1);
	}
	if (fds[1] < 0)
	{
		close(fds[0]);
		return (ft_printf("%s: %s\n", strerror(errno), av[ac - 1]), 1);
	}
	return (0);
}
