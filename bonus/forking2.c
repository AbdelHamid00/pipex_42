/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:47:17 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 11:50:25 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	close_back(int **tube, int pos)
{
	while (pos > 0)
	{
		close(tube[pos - 1][0]);
		close(tube[pos - 1][1]);
		pos--;
	}
	return (0);
}

int	open_pipes(int **tube, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pipe(tube[i]) == -1)
			return (close_back(tube, i));
		i++;
	}
	return (1);
}

int	**alloc_tube(int size)
{
	int	i;
	int	**tube;

	i = 0;
	tube = malloc(sizeof(int *) * size);
	if (!tube)
		return (NULL);
	while (i < size)
	{
		tube[i] = malloc(sizeof(int) * 2);
		if (!tube[i])
			return (NULL);
		i++;
	}
	return (tube);
}
