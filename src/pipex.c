/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/01/28 17:28:36 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	first_child(int pipe_fd[2], char *cmd, t_global *files)
{
	char	*path_cmd;

	if (dup2(files->input_fd, STDIN_FILENO) == -1)
		return (-1);
	files->cmd_split1 = ft_split(cmd, ' ');
	if (!files->cmd_split1)
		return (-1);
	path_cmd = get_cmd_path(files->envp, files->cmd_split1[0]);
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		return (-1);
	if (execve(path_cmd, files->cmd_split1, 0) == -1)
		return (-1);
	return (0);
}

int	last_child(int pipe_fd[2], char *cmd, t_global *files)
{
	char	*path_cmd;

	if (dup2(files->output_fd, STDOUT_FILENO) == -1)
		return (-1);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		return (-1);
	files->cmd_split2 = ft_split(cmd, ' ');
	if (!files->cmd_split2)
		return (-1);
	path_cmd = get_cmd_path(files->envp, files->cmd_split2[0]);
	close(pipe_fd[1]);
	if (execve(path_cmd, files->cmd_split2, 0) == -1)
		return (-1);
	return (0);
}

int	pipex(int argc, char **argv, t_global *files)
{
	int		pipe_fd[2];
	pid_t	process1;
	pid_t	process2;

	if (pipe(pipe_fd) < 0)
		return (-1);
	process1 = fork();
	if (process1 < 0)
		return (-1);
	else if (process1 == 0)
		first_child(pipe_fd, argv[2], files);
	process2 = fork();
	if (process2 < 0)
		return (-1);
	else if (process2 == 0)
		last_child(pipe_fd, argv[argc - 2], files);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(process1, 0, 0);
	waitpid(process2, 0, 0);
	free_splits(files);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_global	files;

	if (argc >= 5)
	{
		files.cmd_split1 = 0;
		files.cmd_split2 = 0;
		files.envp = envp;
		files.input_fd = open(argv[1], O_CREAT | O_RDONLY, 0664);
		if (files.input_fd < 0)
			return (-1);
		files.output_fd = open(argv[argc - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (files.output_fd < 0)
			return (close(files.input_fd), -1);
		if (pipex(argc, argv, &files) < 0)
			perror("Error\n");
		close(files.input_fd);
		close(files.output_fd);
	}
	else
		ft_printf("Error: bad number of arguments\n");
	return (0);
}
