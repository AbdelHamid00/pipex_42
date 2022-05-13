/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:18:19 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 13:18:43 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_n(char const *s1, char const *s2);
char	*ft_strjoin_error(char const *s1);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		there_is_slash(char *arg);
char	**my_path(char *oldenv);
int		search_path(char **env);
int		checker_path(char *env, char *path);
int		ft_strlen(const char *s);

#endif
