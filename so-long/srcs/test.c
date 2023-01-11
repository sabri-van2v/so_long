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

	mlx = mlx_init();
	mlx_windows = mlx_new_window(mlx, 800, 800, "letsgooooo");
	img.img = mlx_new_image(mlx, 800, 800);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int       a = 200;
	int        b = 200 + (3.14 * 100 - 1);
	while (b < 200 + (3.14 * 100))
	{
		if (a >= 200 && (b > 200 && b < 200 + (3.14 * 100)))
			my_mlx_pixel_put(&img, b-- , a++ , 0x00FF0000);
		else if ((a > 200 && a < 200 + (3.14 * 100)) && (b <= 200))
			my_mlx_pixel_put(&img, b-- , a-- , 0x00FF0000);
		else if (a <= 200 && (b <= 200))
			my_mlx_pixel_put(&img, b++ , a-- , 0x00FF0000);
		else if (a <= 200 && (b > 200 && b <= 200 + (3.14 * 100) + 1))
			my_mlx_pixel_put(&img, b++ , a++ , 0x00FF0000);
	}
	mlx_put_image_to_window(mlx, mlx_windows, img.img, 0, 0);
	  mlx_loop(mlx);
}