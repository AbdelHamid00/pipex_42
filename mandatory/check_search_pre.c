/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_search_pre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:09:16 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 13:12:17 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
