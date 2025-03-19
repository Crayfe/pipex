/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/20 00:22:54 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perform_cmd(char *raw_cmd, char **envp)
{
	char	**split_cmd;
	char	*path_cmd;

	if (ft_strlen(raw_cmd) < 1)
		print_error_and_exit("Error: void command", 1);
	split_cmd = ft_split(raw_cmd, ' ');
	path_cmd = get_cmd_path(envp, split_cmd[0]);
	if (!path_cmd)
	{
		free_2d_str(split_cmd);
		print_error_and_exit("Error: non existing command", 127);
	}
	if (execve(path_cmd, split_cmd, envp) == -1)
	{
		free_2d_str(split_cmd);
		print_error_and_exit("Error with exec\n", 1);
	}
}

void	first_child(int *pipe_fd, char **argv, char **envp)
{
	int		fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		print_error_and_exit("Error opening file", 1);
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pipe_fd[0]);
	perform_cmd(argv[2], envp);
}

void	last_child(int *pipe_fd, char **argv, char **envp)
{
	int		fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		print_error_and_exit("Error opening file", 1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	perform_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			print_error_and_exit("Failed pipe", 1);
		pid = fork();
		if (pid == -1)
			print_error_and_exit("Failed fork", 1);
		if (pid == 0)
			first_child(pipe_fd, argv, envp);
		waitpid(pid, 0, 0);
		last_child(pipe_fd, argv, envp);
	}
	else
		print_error_and_exit("Error: incorrect number of aguments\n", 1);
	return (0);
}
