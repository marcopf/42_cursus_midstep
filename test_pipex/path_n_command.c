/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_n_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:41:00 by marco             #+#    #+#             */
/*   Updated: 2023/02/23 19:41:52 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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