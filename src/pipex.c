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

int pipex(int pipe_fd[2], int argc, char **argv, char **envp)
{
    pid_t   process;
    char    *input_file;
    char    *output_file;

    input_file = argv[1];
    output_file = argv[argc - 1];
    (void)pipe_fd;
    (void)envp;
    ft_printf("Input: %s\n", input_file);
    ft_printf("Output: %s\n", output_file);
    process = fork();
    if (process < 0)
        ft_printf("Error using fork()\n");
    else if (process == 0)
        ft_printf("Child process\n");
    else if (process > 0)
        ft_printf("Father process\n");

    return (0);
}
int father_process();
int child_process();
/*
    envp: variables de entorno
*/
int main(int argc, char **argv, char **envp)
{
    int     pipe_fd[2];
    /*
    int     i = 0;
    while (envp[i])
        ft_printf("%s\n", envp[i++]);
    */
    char **paths;
    paths = get_paths(envp);
    if (paths)
    {
        ft_printf("\n\n%s\n", find_cmd_path(paths, "ls"));
        int     i = 0;
        while (paths[i])
            free(paths[i++]);
        free(paths);
    }
    else
        ft_printf("Error: PATH not found\n");
    if (argc == 5)
    {
        //ft_printf("PIPEX!\n");
        if (pipe(pipe_fd) < 0)
            return (1);
        pipex(pipe_fd, argc, argv, envp);
    }
    else
        ft_printf("Error: bad number of arguments\n");
    return (0);
}
