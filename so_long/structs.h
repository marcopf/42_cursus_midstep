#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image {
	void	*floor;
	void	*border;
	void	*item;
	void	*open_door;
	void	*player;
	void	*c_door;
	int		offset_x;
	int		offset_y;
	int		img_width;
	int		img_height;

}	t_imgs;

typedef struct e_player{
	void	*top;
	void	*bottom;
	void	*left;
	void	*right;
	int		x;
	int		y;
	int		moves;
	int		collectibles;
}	t_player;

typedef struct e_game {
	void		*mlx;
	void		*mlx_win;
	t_imgs		imgs;
	t_player	player;
	char		**map;
	int			moves;
	int			img_width;
	int			img_height;
	int			done;

}	t_game;

#endif
