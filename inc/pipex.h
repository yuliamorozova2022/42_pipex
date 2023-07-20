/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorozov <ymorozov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:09:58 by ymorozov          #+#    #+#             */
/*   Updated: 2023/04/04 10:26:39 by ymorozov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
/*<fcntl.h>  for open(), dup(), dup2()*/
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "./../libft/lib_ft.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}				t_cmd;

//pipex.c
int		pipex_manager(int *arr_oper, char **argv, char **envp, int *fd);
int		pipex(int *fd, t_cmd *cmd, char **envp);

//utils1.c
char	*get_path(char *command, char **envp);
int		size_of_arr(char **array);
char	*find_path(char *cmd, char **array);
void	ft_free(char **array, size_t n);

//utils2.c
char	**ft_split_path(char const *s, char c);

//utils3.c
t_cmd	*get_struct(char *command, char **envp);
void	free_struct(t_cmd *cmd);
void	close_all(int fd1, int fd2);

#endif
