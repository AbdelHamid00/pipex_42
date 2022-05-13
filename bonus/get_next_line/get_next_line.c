/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:46:12 by aabouzid          #+#    #+#             */
/*   Updated: 2021/12/04 23:51:51 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*just_avant(char *str)
{
	char	*avant;
	int		i;
	int		j;

	i = 0;
	avant = NULL;
	while (str && str[i] && str[i] != '\n')
		i++;
	i++;
	avant = malloc(sizeof(char) * (i + 1));
	if (!avant)
		return (NULL);
	j = 0;
	while (str && str[j] && j < i)
	{
		avant[j] = str[j];
		j++;
	}
	avant[j] = '\0';
	return (avant);
}

char	*just_apres(char *str)
{
	int		i;
	int		j;
	char	*apres;

	i = 0;
	if (!ft_strchr(str, '\n'))
		return (0);
	while (str && str[i] && str[i] != '\n')
		i++;
	apres = malloc(ft_strlen(str) - i + 1);
	if (!apres)
		return (0);
	j = 0;
	i++;
	while (str && str[i])
	{
		apres[j] = str[i];
		j++;
		i++;
	}
	apres[j] = '\0';
	return (apres);
}

int	lets_search(char **str, int fd)
{
	char	*buf;
	char	*temp;
	int		r;

	buf = (char *)malloc(sizeof(char) * (1 + 1));
	if (!buf)
		return (0);
	r = 1;
	while (r != 0)
	{
		r = read(fd, buf, 1);
		if (r < 0)
		{
			free(buf);
			return (0);
		}
		buf[r] = 0;
		temp = *str;
		*str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buf);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*temp;
	char		*retu;
	int			r;

	if (fd < 0)
		return (0);
	r = lets_search(&str, fd);
	if (!r)
		return (0);
	retu = just_avant(str);
	temp = str;
	str = just_apres(temp);
	free(temp);
	if (!*retu)
	{
		free(retu);
		temp = str;
		str = NULL;
		free(temp);
		retu = NULL;
	}
	return (retu);
}
