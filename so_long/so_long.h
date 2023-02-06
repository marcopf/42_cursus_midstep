#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "structs.h"
# include <time.h>

char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*get_next_line(int fd);
int		counter(char *path);
char	**map_maker(char *path);
void	free_map(char **strs);
int		is_rect(char **map);
int		get_y(char **strs);
int		border_wall(char **map);
int		is_valid_map(char **map);
void	draw_map(t_game *game);
void	img_init(t_game *game);
void	free_map(char **strs);
void	print_mat(char **strs);
int		key_hook(int key, t_game *game);
void	locate_player(t_game *game);
void	collectibles_setter(t_game *game);
int		can_we_get_out(char **map);
void	finish_game(t_game *game);
int     move_charizard(t_game *game);
void	locate_charizard(t_game *game);

#endif
