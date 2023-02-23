/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:31:08 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/21 15:20:28 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

char **command_maker(char **argv, int argc, int el)
{
	char	**strs;
	char	*base;
	char	*command;

	strs = ft_split(argv[el], ' ');
	base = ft_strdup("/bin/");
	command = ft_strjoin(base, strs[0]);
	free(strs[0]);
	free(base);
	strs[0] = command;
	return (strs);
}

int main(int argc, char **argv, char **envp) 
{
	t_pipex	pipex;

	if (pipe(pipex.pipe_fd) == -1)
		return (1);
	pipex.infile_fd = open(argv[1], O_RDONLY);
	pipex.outfile_fd = open(argv[3], O_RDONLY | O_CREAT);
	pipex.command1 = command_maker(argv, argc, 2);
	pipex.command2 = command_maker(argv, argc, 3);
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return (2);
	if (pipex.pid1 == 0)
	{
		close(pipex.pipe_fd[0]);
		dup2(pipex.pipe_fd[1], STDOUT_FILENO);
		dup2(pipex.infile_fd, 0);
		close(pipex.pipe_fd[1]);
		execve(pipex.command1[0], pipex.command1, NULL);
	}
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		return (3);
	if (pipex.pid2 == 0)
	{
		dup2(pipex.pipe_fd[0], STDIN_FILENO);
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		execve(pipex.command2[0], pipex.command2, NULL);
	}
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	close(pipex.outfile_fd);
	close(pipex.infile_fd);
	close(pipex.infile_fd);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	ft_free(pipex.command1);
	ft_free(pipex.command2);
}