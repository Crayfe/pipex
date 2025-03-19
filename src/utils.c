/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/20 00:16:24 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error_and_exit(char *error, int status)
{
	if (error)
		perror(error);
	exit(status);
}

char	*find_cmd_path(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*aux_free;

	i = 0;
	cmd_path = 0;
	while (paths[i])
	{
		aux_free = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(aux_free, cmd);
		free(aux_free);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		else
			free(cmd_path);
		i++;
	}
	return (0);
}

char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i])
		return (ft_split(envp[i] + 5, ':'));
	return (0);
}

char	*get_cmd_path(char **envp, char *cmd)
{
	char	*cmd_path;
	char	**paths;
	int		i;

	paths = get_paths(envp);
	if (!paths)
		return (0);
	cmd_path = find_cmd_path(paths, cmd);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (cmd_path);
}
