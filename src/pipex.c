/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/01/10 13:19:21 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int first_child(int pipe_fd[2], char *input_file, char *cmd, char **envp)
{
    char    **paths;
    char    *path_cmd;
    int     input_fd;
    int     i;
    char    **cmd_split;

    input_fd = open(input_file, O_CREAT | O_RDONLY, 0664);
    if (input_fd < 0)
        return (-1);
    if (dup2(input_fd, STDIN_FILENO) == -1)
        return (close(input_fd), -1);

    paths = get_paths(envp);
    if (!paths)
        return (-1);
    cmd_split = ft_split(cmd, ' ');
    if(!cmd_split)
        return (-1);
    path_cmd = find_cmd_path(paths, cmd_split[0]);
    if (!path_cmd)
        return (-1);
    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);
    close(pipe_fd[0]);
    if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
        return (-1);
    if (execve(path_cmd, cmd_split, 0) == -1)
        return (-1);
    

    /*
    paths = get_paths(envp);
    if (paths)
    {
        ft_printf("\n\n%s\n", find_cmd_path(paths, "ls"));
        i = 0;
        while (paths[i])
            free(paths[i++]);
        free(paths);
    }
    else
        ft_printf("Error: PATH not found\n");
    */
    return (0);
}

int last_child(int pipe_fd[2], char *output_file, char *cmd, char **envp)
{
    char    **paths;
    char    *path_cmd;
    int     output_fd;
    int     i;
    char    **cmd_split;

    output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (output_fd < 0)
        return (-1);
    if (dup2(output_fd, STDOUT_FILENO) == -1)
        return (close(output_fd), -1);

    paths = get_paths(envp);
    if (!paths)
        return (-1);
    cmd_split = ft_split(cmd, ' ');
    if(!cmd_split)
        return (-1);
    path_cmd = find_cmd_path(paths, cmd_split[0]);
    if (!path_cmd)
        return (-1);
    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);
    if (execve(path_cmd, cmd_split, 0) == -1)
        return (-1);
    return (0);
}
int pipex(int argc, char **argv, char **envp)
{
    int     pipe_fd[2];
    int     status;
    pid_t   process1;
    pid_t   process2;

    (void)argc;
    if (pipe(pipe_fd) < 0)
        return (-1);
    process1 = fork();
    if (process1 < 0)
        return (-1);
    else if (process1 == 0)
        first_child(pipe_fd, argv[1], argv[2], envp);
    else if (process1 > 0)
    {
        ft_printf("Father process\n");
        close(pipe_fd[1]);
        if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
            return (-1);
        process2 = fork();
        if (process2 < 0)
            return (-1);
        else if (process2 == 0)
            last_child(pipe_fd, argv[3], argv[4], envp);
        else
        {
            while (waitpid(-1, &status, 0) > 0);
        }

    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    if (argc >= 5)
        pipex(argc, argv, envp);
    else
        ft_printf("Error: bad number of arguments\n");
    return (0);
}
