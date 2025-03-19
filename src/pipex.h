/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/19 19:29:24 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define FIRST 1
# define LAST 2
# include "../libft/src/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

void	print_error_and_exit(char *error, int status);
char	*find_cmd_path(char **paths, char *cmd);
char	**get_paths(char **envp);
char	*get_cmd_path(char **envp, char *cmd);

#endif