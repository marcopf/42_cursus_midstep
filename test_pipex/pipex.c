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

int	better_execve_1(char **argv, int argc)
{
	char	*base;
	char	*command;
	char	**strs;
	int		i;

	strs = (char **)malloc(sizeof(char *) * argc);
	strs[argc] = 0;
	i = 0;
	while (strs[++i])
		strs[i - 1] = argv[i];
	strs[i - 1] = 0;
	base = ft_strdup("/bin/");
	strs[0] = ft_strjoin(base, argv[1]);
	execve(strs[0], strs, NULL);
}

int	main(int argc, char **argv)
{
	int	pid1;

	pid1 = fork();
	if (pid1 < 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
	{
		better_execve_1(argv, argc);
	}
	
}