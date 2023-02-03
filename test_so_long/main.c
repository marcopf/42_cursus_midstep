#include <mlx.h>

typedef struct	s_data {
	void	*floor;
	void	*border;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		img_height;
	int		img_width;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void init_map(int x, int y, void *mlx)
{
	int		i;
	int		j;
	void	*mlx_win;
	t_data	map;

	i = 0;
	mlx_win = mlx_new_window(mlx, x * 62, y * 62, "Hello world!");
	map.floor = mlx_xpm_file_to_image(mlx, "so_long_img/tile_floor.xpm", &map.img_width, &map.img_height);
	map.border = mlx_xpm_file_to_image(mlx, "so_long_img/wall.xpm", &map.img_width, &map.img_height);
	while (i < x * 62)
	{
		j = 0;
		while (j < y * 62)
		{
			mlx_put_image_to_window(mlx, mlx_win, map.floor, i, j);
			j += 62;
		}
		i += 62;
	}
	i = 0;
	while (i < x * 62)
	{
		j = 0;
		while (j < y * 62)
		{
			if (j == 0 || j > (y * 62) - 64 || i == 0 || i > (x * 62) - 64)
				mlx_put_image_to_window(mlx, mlx_win, map.border, i, j);
			j += 62;
		}
		i += 62;
	}
}

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	init_map(10, 10, mlx);
	mlx_loop(mlx);
}
