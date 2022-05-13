/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_dup_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:05:17 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 13:06:47 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin_n(char const *s1, char const *s2)
{
	char	*p;
	int		j;
	int		i;

	if (!s1 || !s2)
		return (0);
	j = 0;
	i = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!p)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\n';
	p[++i] = '\0';
	return (p);
}

char	*ft_strjoin_error(char const *s1)
{
	char	*ptr;
	char	*tmp;

	tmp = ft_strjoin(s1, " :");
	ptr = ft_strjoin_n(tmp, strerror(errno));
	free(tmp);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (p == 0)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (!s1[i])
		return (1);
	return (0);
}
