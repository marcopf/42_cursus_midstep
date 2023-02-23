/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:31:49 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/21 10:56:52 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct e_pipex{
    int     pipe_fd[2];
    int     infile_fd;
    int     outfile_fd;
    int     pid1;
    int     pid2;
    char    **command1;
    char    **command2;

}   t_pipex;

# include "libft/libft.h"
# include "ft_printf/libftprintf.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

#endif