/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/01/28 14:22:20 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	first_child(int pipe_fd[2], char *cmd, t_global *files)
{
	char	*path_cmd;
	char	**cmd_split;

	if (dup2(files->input_fd, STDIN_FILENO) == -1)
		return (-1);
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		return (-1);
	path_cmd = get_cmd_path(files->envp, cmd_split[0]);
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		return (-1);
	if (execve(path_cmd, cmd_split, 0) == -1)
		return (-1);
    return (0);
}

int last_child(int pipe_fd[2], char *cmd, t_global *files)
{
	char	*path_cmd;
	char	**cmd_split;

	if (dup2(files->output_fd, STDOUT_FILENO) == -1)
		return (-1);
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		return (-1);
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		return (-1);
	path_cmd = get_cmd_path(files->envp, cmd_split[0]);
	if (execve(path_cmd, cmd_split, 0) == -1)
		return (-1);
	return (0);
}

int	pipex(int argc, char **argv, t_global *files)
{
	int	pipe_fd[2];
	pid_t	process;

	if (pipe(pipe_fd) < 0)
		return (-1);
	process = fork();
	if (process < 0)
		return (-1);
	else if (process == 0)
		first_child(pipe_fd, argv[2], files);
	else
	{
		process = fork();
		if (process < 0)
			return (-1);
		else if (process == 0)
			last_child(pipe_fd, argv[argc - 2], files);
		else
			while(waitpid(-1, 0, 0) > 0);

	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_global	files;

	if (argc >= 5)
	{
		files.envp = envp;
		files.input_fd = open(argv[0], O_CREAT | O_RDONLY, 0664);
		if (files.input_fd < 0)
			return (-1);
		files.output_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (files.output_fd < 0)
			return (close(files.input_fd), -1);
		pipex(argc, argv, &files);
		close(files.input_fd);
		close(files.output_fd);
	}
	else
		ft_printf("Error: bad number of arguments\n");
	return (0);
}
