/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:00:25 by ymorozov          #+#    #+#             */
/*   Updated: 2023/04/04 10:53:33 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fds[2];
	int	i;

	if (ac == 5)
	{
		i = 2;
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
		if (pipex_manager((int []){i, ac - 1}, av, envp, fds) == 1)
			return (1);
		return (close_all(fds[0], fds[1]), 0);
	}
	return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
}
