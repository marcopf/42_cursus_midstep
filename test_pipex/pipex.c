/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:31:08 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/23 16:54:49 by mpaterno         ###   ########.fr       */
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

void	free_cmd_n_file(t_pipex *pipex)
{
	close(pipex->outfile_fd);
	close(pipex->infile_fd);
	ft_free(pipex->cmd1);
	ft_free(pipex->cmd2);
}

char	*line_composer(char **strs)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = 0;
	temp2 = ft_strdup(strs[1]);
	while (strs[++i])
	{
		if (strs[i + 1])
		{
			temp = ft_strjoin(temp2, " ");
			free(temp2);
			temp2 = ft_strjoin(temp, strs[i + 1]);
			free(temp);
		}
	}
	return (temp2);
}

int	sub_proc(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		return (-1);
	if (pipex->pid1 == 0)
	{
		close(pipex->pipe_fd[0]);
		dup2(pipex->pipe_fd[1], 1);
		dup2(pipex->infile_fd, 0);
		execve(pipex->cmd1[0], pipex->cmd1, NULL);
	}
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		return (-1);
	if (pipex->pid2 == 0)
	{
		dup2(pipex->pipe_fd[0], 0);
		dup2(pipex->outfile_fd, 1);
		close(pipex->pipe_fd[1]);
		execve(pipex->cmd2[0], pipex->cmd2, NULL);
	}
	return (1);
}

char	**get_line(char **envp)
{
	int		i;
	int		flag;
	char	**ret;

	flag = 0;
	i = -1;
	ret = 0;
	while (envp[++i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			flag = 1;
			break ;
		}
	}
	if (flag)
		ret = ft_split((envp[i] + 5), ':');
	return (ret);
}

char	**path_n_command(t_pipex *pipex, char **argv, int el, char **envp)
{
	char	*temp;
	char	**command;

	pipex->paths = get_line(envp);
	pipex->cmd_i = -1;
	command = ft_split(argv[el], ' ');
	while (pipex->paths[++pipex->cmd_i])
	{
		temp = ft_strdup(pipex->paths[pipex->cmd_i]);
		free(pipex->paths[pipex->cmd_i]);
		pipex->paths[pipex->cmd_i] = ft_strjoin(temp, "/");
		free(temp);
		temp = ft_strdup(pipex->paths[pipex->cmd_i]);
		free(pipex->paths[pipex->cmd_i]);
		pipex->paths[pipex->cmd_i] = ft_strjoin(temp, command[0]);
		free(temp);
	}
	pipex->cmd_i = -1;
	while (pipex->paths[++pipex->cmd_i])
		if (!access(pipex->paths[pipex->cmd_i], 0))
			break ;
	free(command[0]);
	command[0] = ft_strdup(pipex->paths[pipex->cmd_i]);
	ft_free(pipex->paths);
	return (command);
}

void	protect_space(char *strs)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strchr(strs, '\"');
	if (str)
	{
		i += 1;
		while (str[++i] && str[i] != '\"')
			if (str[i] == ' ')
				str[i] = '#';
	}
	str = ft_strchr(strs, '\'');
	if (str)
	{
		i += 1;
		while (str[++i] && str[i] != '\'')
			if (str[i] == ' ')
				str[i] = '#';
	}
}

void	convert(char **strs)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	while (strs[++i])
	{
		if (ft_strchr(strs[i], '#'))
		{
			str = ft_strchr(strs[i], '#');
			j = -1;
			while (str[++j] && str[j] != '\'')
			{
				if (str[j] == '#')
					str[j] = ' ';
			}
		}
	}
}

int	main(int argc, char **argv, char **envp) 
{
	t_pipex	pipex;
	char	*temp;

	if (pipe(pipex.pipe_fd) == -1)
		return (1);
	protect_space(argv[2]);
	protect_space(argv[3]);
	pipex.infile_fd = open(argv[1], O_RDONLY);
	pipex.outfile_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	pipex.cmd1 = path_n_command(&pipex, argv, 2, envp);
	pipex.cmd2 = path_n_command(&pipex, argv, 3, envp);
	convert(pipex.cmd1);
	convert(pipex.cmd2);
	temp = ft_strtrim(pipex.cmd2[1], "\'");
	free(pipex.cmd2[1]);
	pipex.cmd2[1] = temp;
	if (sub_proc(&pipex) < 0)
		return (1);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_cmd_n_file(&pipex);
}