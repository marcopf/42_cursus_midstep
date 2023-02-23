/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:31:49 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/23 13:19:14 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/libftprintf.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct e_pipex{
	int		pipe_fd[2];
	int		infile_fd;
	int		outfile_fd;
	int		pid1;
	int		pid2;
	char	**cmd1;
	char	**cmd2;
	int		cmd_i;
	char	**paths;

}	t_pipex;

#endif