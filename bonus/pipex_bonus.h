/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:07:11 by aabouzid          #+#    #+#             */
/*   Updated: 2022/05/13 13:08:43 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

int		checker_path(char *env, char *path);
int		ft_cmp(char *s1, char *s2);
int		search_path(char **env);
char	**my_path(char *oldenv);
void	path_cmd(char **path, char **arg);
int		there_is_slash(char *arg);
void	fct_exec(char **path, char **arg);
int		close_back(int **tube, int pos);
int		open_pipes(int **tube, int size);
int		**alloc_tube(int size);
char	**first_here_doc(char **argv, int argc, int **tube);
void	first_fork(char **argv, int **tube, char **path, int argc);
void	last_fork(char **argv, int **tube, char **path, int argc);
int		ft_strlen_tab(char **c);
void	fork_i(char **argv, int **tube, char **path, int i);
void	print_pipe(int argc);
void	read_here_doc(char *argv2, char **buf, int argc, char **p);
void	read_and_write(char **argv, int **tube, int argc);
void	forking(char **argv, char **path, int argc, int **tube);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_n(char const *s1, char const *s2);
char	*ft_strjoin_error(char const *s1);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
