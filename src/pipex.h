/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/01/28 16:00:01 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/src/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_global
{
	int		input_fd;
	int		output_fd;
	char	**envp;
}	t_global;

char	*find_cmd_path(char **paths, char *cmd);
char	**get_paths(char **envp);
char	*get_cmd_path(char **envp, char *cmd);
