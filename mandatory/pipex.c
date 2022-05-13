/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:13:29 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 13:18:04 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fct_exec(char **path, char **arg)
{
	int		i;
	char	*tmp;

	i = 0;
	if (there_is_slash(arg[0]))
		execve(arg[0], arg, NULL);
	else
	{
		while (path[i])
		{
			tmp = ft_strjoin(path[i], arg[0]);
			if (execve(tmp, arg, NULL) == -1)
				i++;
			else
				free(tmp);
		}
	}
	tmp = ft_strjoin_n("command not found: ", arg[0]);
	write(2, tmp, ft_strlen(tmp));
	free(tmp);
	exit(2);
}

void	last_fork(char **argv, int *tube, char **path, int argc)
{
	int		pid;
	int		fd;
	char	**arg;

	pid = fork();
	if (pid == 0)
	{
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			exit(4);
		dup2(fd, 1);
		dup2(tube[0], 0);
		close(tube[0]);
		close(tube[1]);
		arg = ft_split(argv[3], ' ');
		fct_exec(path, arg);
	}
}

void	first_fork(char **argv, int *tube, char **path)
{
	int		pid;
	int		fd;
	char	**arg;
	char	*ms;

	pid = fork();
	if (pid == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ms = ft_strjoin_error(argv[1]);
			write(2, ms, ft_strlen(ms));
			free(ms);
			exit(3);
		}
		dup2(fd, 0);
		dup2(tube[1], 1);
		close(tube[1]);
		close(tube[0]);
		arg = ft_split(argv[2], ' ');
		fct_exec(path, arg);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int		i;
	char	**path;
	int		tube[2];

	i = search_path(env);
	if (argc != 5 || i == -1 || pipe(tube) == -1)
		return (1);
	path = my_path(env[i]);
	first_fork(argv, tube, path);
	last_fork(argv, tube, path, argc);
	close(tube[0]);
	close(tube[1]);
	while (1)
	{
		if (wait(NULL) == -1)
			break ;
	}
	return (0);
}
