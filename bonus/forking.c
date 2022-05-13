/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:58:35 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 13:04:46 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_fork(char **argv, int **tube, char **path, int argc)
{
	int		pid;
	char	**arg;

	pid = fork();
	if (pid == 0)
	{
		if (!ft_cmp(argv[1], "here_doc"))
			arg = first_here_doc(argv, argc, tube);
		else
		{
			dup2(tube[0][0], 0);
			dup2(tube[1][1], 1);
			close_back(tube, argc - 5);
			arg = ft_split(argv[3], ' ');
		}
		fct_exec(path, arg);
	}
}

void	last_fork(char **argv, int **tube, char **path, int argc)
{
	int		pid;
	int		fd;
	char	**arg;

	pid = fork();
	if (pid == 0)
	{
		if (!ft_cmp(argv[1], "here_doc"))
			fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			exit(4);
		dup2(fd, 1);
		dup2(tube[argc - 5][0], 0);
		close_back(tube, argc - 4);
		arg = ft_split(argv[argc - 2], ' ');
		fct_exec(path, arg);
	}
}

int	ft_strlen_tab(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	fork_i(char **argv, int **tube, char **path, int i)
{
	int		pid;
	char	**arg;
	int		argc;

	if (ft_cmp(argv[1], "here_doc"))
		i++;
	argc = ft_strlen_tab(argv);
	pid = fork();
	if (pid == 0)
	{
		dup2(tube[i][0], 0);
		dup2(tube[i + 1][1], 1);
		close_back(tube, argc - 4);
		arg = ft_split(argv[i + 3], ' ');
		fct_exec(path, arg);
	}
}

void	print_pipe(int argc)
{
	while (argc - 5 > 0)
	{
		write(1, "pipe ", 5);
		argc--;
	}
}
