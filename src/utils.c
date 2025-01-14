/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/01/10 13:19:21 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char    *find_cmd_path(char **paths, char *cmd)
{
    int     i;
    char    *cmd_path;
    char    *aux_free;

    i = 0;
    cmd_path = 0;
    
    while (paths[i])
    {
        aux_free = ft_strjoin(paths[i], "/");
        cmd_path = ft_strjoin(aux_free, cmd);
        free(aux_free);
        if (access(cmd_path, X_OK) == 0)
            return (cmd_path);
        else
            free(cmd_path);
        i++;
    }
    return (0);
}
char    **get_paths(char **envp)
{
    int     i;

    i = 0;
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
        i++;
    if (envp[i])
        return (ft_split(envp[i] + 5, ':'));
    return (0);
}