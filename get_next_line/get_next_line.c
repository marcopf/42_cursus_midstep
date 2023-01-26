/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:17:14 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/26 17:11:17 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_substr(char const *str, unsigned int start, size_t len)
// {
// 	char	*new_str;
// 	size_t	i;

// 	i = 0;
// 	if (!str || start > ft_strlen(str))
// 		return (ft_strdup(""));
// 	new_str = malloc((len + 1) * sizeof(char));
// 	if (!new_str)
// 		return (0);
// 	ft_bzero(new_str, len + 1);
// 	while (i < len && str[start])
// 		new_str[i++] = str[start++];
// 	new_str[i] = 0;
// 	return (new_str);
// }

char	*get_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*ret;

	ret = ft_strdup("");
	while (!ft_strchr(buff, '\n'))
	{
		if (!read(fd, buff, BUFFER_SIZE))
		{
			free(ret);
			return (0);
		}
		buff[BUFFER_SIZE] = 0;
		ret = ft_strjoin(ret, buff);
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
	len1 = ft_strlen((ft_strchr(str, '\n') + 1)) + 1;
	ret = (char **) malloc(2 * sizeof(char *));
	ret[0] = (char *)malloc((len0) * sizeof(char));
	ret[1] = (char *)malloc((len1) * sizeof(char));
	ft_strlcpy(ret[0], str, len0);
	ft_strlcpy(ret[1], (ft_strchr(str, '\n') + 1), len1);
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	
	char		*str;
	//char		**strs;
	char		*ret = 0;

	// if (ft_strchr(buff, '\n'))
	// 	return (ft_substr(buf, 0, ft_strlen(ft_strchr(buff, '\n'))))
	str = ft_strjoin(buff, get_line(fd));
	// strs = parser(str);
	printf("%s", str);
	// ret = ft_strdup(strs[0]);
	// ft_strlcpy(buff, strs[1], ft_strlen(strs[1]) + 1);
	// free(strs[0]);
	// free(strs[1]);
	// free(strs);
	return (ret);
}

int main(void)
{
	int fd;
	char *str = 0;

	fd = open("test.txt", O_RDONLY);
	str=get_next_line(fd);
	printf("%s\n", str);
	free(str);
	// 	str=get_next_line(fd);
	// printf("%s\n", str);
	// free(str);
	// while ((str=get_next_line(fd)))
	// {
	// 	printf("%s", str);
	// 	free(str);
	// }
	// free(str);
	close(fd);
}