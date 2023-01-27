/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:17:14 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/27 16:31:43 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*print_remain(char	*str)
{
	char	*ret;
	char	*new_buff;
	int		i;

	new_buff = ft_strchr(str, '\n') + 1;
	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ret = (char *) malloc((i + 2) * sizeof(char));
	ft_strlcpy(ret, str, i + 2);
	if (ft_strchr(str, '\n') > 0)
		ft_strlcpy(str, new_buff, ft_strlen(new_buff) + 1);
	else
	{
		i = -1;
		while (++i < BUFFER_SIZE)
			str[i] = 0;
	}
	return (ret);
}

char	*get_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		flag;
	char	*ret;
	int		i;

	flag = 1;
	if (fd < 0 || fd >= 1000)
		return (0);
	ret = ft_strdup("");
	buff[BUFFER_SIZE] = 0;
	while (ft_strchr(ret, '\n') == 0 && flag)
	{
		i = -1;
		while (++i < BUFFER_SIZE)
			buff[i] = 0;
		flag = read(fd, buff, BUFFER_SIZE);
		ret = ft_strjoin(ret, buff);
		if (flag == 0 && !*ret)
		{
			free(ret);
			return (0);
		}
	}
	return (ret);
}

char	**parser(char *str)
{
	char	**ret;
	int		len0;
	int		len1;

	if (!str)
		return (0);
	len0 = (ft_strchr(str, '\n') + 1) - str + 1;
	if (ft_strchr(str, '\n') == 0)
		len1 = 0;
	else
		len1 = ft_strlen((ft_strchr(str, '\n') + 1)) + 1;
	ret = (char **) malloc(2 * sizeof(char *));
	ret[0] = (char *)malloc((len0) * sizeof(char));
	ret[1] = (char *)malloc((len1) * sizeof(char));
	ft_strlcpy(ret[0], str, len0);
	if (len1 > 0)
		ft_strlcpy(ret[1], (ft_strchr(str, '\n') + 1), len1);
	free(str);
	return (ret);
}

void	free_all(char *s1, char *s2, char **s3, char *s4)
{
	free(s1);
	free(s2);
	free(s3);
	free(s4);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*full;
	char		*str;
	char		**strs;
	char		*ret;

	if (ft_strchr(buff, '\n'))
		return (print_remain(buff));
	str = get_line(fd);
	if (!str)
	{
		if (buff[0])
			return (print_remain(buff));
		return (0);
	}
	if (ft_strchr(str, '\n') == 0 && !buff[0])
		return (str);
	full = ft_strdup(buff);
	full = ft_strjoin(full, str);
	strs = parser(full);
	ret = ft_strdup(strs[0]);
	ft_strlcpy(buff, strs[1], ft_strlen(strs[1]) + 1);
	free_all(strs[0], strs[1], strs, str);
	return (ret);
}

// int main(void)
// {
// 	int fd;
// 	char *str = 0;

// 	fd = open("/Users/marcopaternostofrosi/Documents/42_cursus/get_next_line/gnlTester/files/multiple_line_no_nl", O_RDONLY);
// 	str=get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 		str=get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 		str=get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 		str=get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 		str=get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	// 	str=get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	// while ((str=get_next_line(fd)))
// 	// {
// 	// 	printf("%s", str);
// 	// 	free(str);
// 	// }
// 	//free(str);
// 	close(fd);
// }
