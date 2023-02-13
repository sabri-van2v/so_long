#include <stdlib.h>
#include <X11/keysym.h>
#include "mlx.h"
#include <X11/X.h>
#include <stdio.h>

// typedef struct s_img
// {
// 	void	*mlx_img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// }	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	**xpm;
}	t_data;

int	release(int key, t_data *data)
{
	int	x;
	int y;

	x = 128;
	y = 128;
	mlx_get_screen_size(data->mlx_ptr, &x, &y);
	if (key == XK_Escape)
	{
		//free(data->img.mlx_img);
		//free(data->xpm);
		mlx_destroy_image(data->mlx_ptr, *(data->xpm));
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (0);
	}
	return (0);
}

int main()
{
	t_data data;
	int	img_width;
	int	img_height;

	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 800, 800, "letsgooooo");
	data.xpm = malloc(sizeof(void *));
	*(data.xpm) = mlx_xpm_file_to_image(data.mlx_ptr, "./img/map.xpm", &img_height, &img_width);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, *(data.xpm), 100, 100);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &release, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}