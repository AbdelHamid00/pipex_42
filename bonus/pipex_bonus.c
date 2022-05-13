/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:50:43 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 12:45:26 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**first_here_doc(char **argv, int argc, int **tube)
{
	int		fd;
	char	*ms;
	char	**arg;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ms = ft_strjoin_error(argv[1]);
		write(2, ms, ft_strlen(ms));
		free(ms);
		exit(3);
	}
	dup2(fd, 0);
	dup2(tube[0][1], 1);
	close_back(tube, argc - 4);
	arg = ft_split(argv[2], ' ');
	return (arg);
}

void	read_here_doc(char *argv2, char **buf, int argc, char **p)
{
	char	*tmp;

	if (ft_cmp(*p, argv2))
	{
		free(*p);
		*p = NULL;
		return ;
	}
	tmp = *buf;
	*buf = ft_strjoin(tmp, *p);
	if (tmp)
		free(tmp);
	free(*p);
	print_pipe(argc);
	write(1, "heredoc> ", 9);
	*p = get_next_line(0);
}

void	read_and_write(char **argv, int **tube, int argc)
{
	char	*p;
	char	*buf;
	char	*argv2;

	buf = NULL;
	argv2 = ft_strjoin(argv[2], "\n");
	print_pipe(argc);
	write(1, "heredoc> ", 9);
	p = get_next_line(0);
	while (p)
		read_here_doc(argv2, &buf, argc, &p);
	if (buf)
	{
		write(tube[0][1], buf, ft_strlen(buf));
		free(buf);
	}
	free(argv2);
}

void	forking(char **argv, char **path, int argc, int **tube)
{
	int	i;

	i = 0;
	if (ft_cmp(argv[1], "here_doc"))
	{
		if (argc < 6)
			exit(2);
		read_and_write(argv, tube, argc);
		first_fork(argv, tube, path, argc);
		while (i < argc - 6)
		{
			fork_i(argv, tube, path, i);
			i++;
		}
	}
	else
	{
		first_fork(argv, tube, path, argc);
		while (i < argc - 5)
		{
			fork_i(argv, tube, path, i);
			i++;
		}
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int		i;
	char	**path;
	int		**tube;

	tube = alloc_tube(argc - 4);
	i = search_path(env);
	if (argc < 5 || i == -1 || !open_pipes(tube, argc - 4) || !tube)
		return (1);
	path = my_path(env[i]);
	forking(argv, path, argc, tube);
	last_fork(argv, tube, path, argc);
	close_back(tube, argc - 4);
	while (1)
	{
		if (wait(NULL) == -1)
			break ;
	}
	return (0);
}
