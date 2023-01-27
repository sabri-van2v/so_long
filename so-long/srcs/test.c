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
	int	x = 200;
	int	y = 200;
	int	cos = 100;
	int sin = 0;
	int	c = 3.14 * 200;
	while (c > 0)
	{
		my_mlx_pixel_put(&img, x + cos, y + sin, 0x00FF0000);
		if ((cos >= 0 && cos <= 100) && (sin >= 0 && sin <= 100))
		{
			cos--;
			sin++;
		}
		else if ((cos >= -100 && cos <= 0) && (sin >= 0 && sin <= 100))
		{
			cos--;
			sin--;
		}
		else if ((cos >= -100 && cos <= 0) && (sin >= -100 && sin <= 0))
		{
			cos++;
			sin--;
		}
		else if ((cos >= 0 && cos <= 100) && (sin >= -100 && sin <= 0))
		{
			cos++;
			sin++;
		}
		c--;
	}
	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_windows, img.img, 0, 0);
	  mlx_loop(mlx);
}