/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:43:35 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 11:47:02 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	checker_path(char *env, char *path)
{
	int	i;

	i = 0;
	while (env[i] == path[i] && env[i] && path[i])
		i++;
	if (i == ft_strlen(path))
		return (1);
	else
		return (0);
}

int	search_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (checker_path(env[i], "PATH="))
			return (i);
		i++;
	}
	return (-1);
}

int	there_is_slash(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	**my_path(char *oldenv)
{
	char	*newenv;
	int		i;
	char	**path;

	i = 0;
	newenv = malloc(sizeof(char) * (ft_strlen(oldenv) - 4));
	while (oldenv[i + 5])
	{
		newenv[i] = oldenv[i + 5];
		i++;
	}
	newenv[i] = '\0';
	path = ft_split(newenv, ':');
	free(newenv);
	i = 0;
	while (path[i])
	{
		newenv = path[i];
		path[i] = ft_strjoin(newenv, "/");
		free(newenv);
		i++;
	}
	return (path);
}

void	path_cmd(char **path, char **arg)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], arg[0]);
		free(tmp);
		i++;
	}
}
