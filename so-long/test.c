#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void *mlx;
	t_data img;
	void *mlx_windows;
	void *test_img;
	void *test_img2;
	void *test_img3;
	void *test_img4;
	void *test_img5;
	int	img_width;
	int	img_height;
	int	i;
	int	j;

	i = 0;
	mlx = mlx_init();
	mlx_windows = mlx_new_window(mlx, 800, 800, "letsgooooo");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	test_img2 = mlx_xpm_file_to_image(mlx, "./img/map.xpm", &img_width, &img_height);
	test_img = mlx_xpm_file_to_image(mlx, "./img/bastien.xpm", &img_width, &img_height);
	test_img3 = mlx_xpm_file_to_image(mlx, "./img/arbre.xpm", &img_width, &img_height);
	test_img4 = mlx_xpm_file_to_image(mlx, "./img/micro.xpm", &img_width, &img_height);
	test_img5 = mlx_xpm_file_to_image(mlx, "./img/kirby.xpm", &img_width, &img_height);
	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	while (i < 800)
	{
		j = 0;
		while (j < 800)
		{
			mlx_put_image_to_window(mlx, mlx_windows, test_img2, j, i);
			j += 64;
		}
		i += 64;
	}
	mlx_put_image_to_window(mlx, mlx_windows, test_img, 64, 0);
	mlx_put_image_to_window(mlx, mlx_windows, test_img3, 64, 192);
	mlx_put_image_to_window(mlx, mlx_windows, test_img4, 64, 320);
	mlx_put_image_to_window(mlx, mlx_windows, test_img5, 64, 448);
	mlx_loop(mlx);
}