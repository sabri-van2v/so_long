#include <stdlib.h>
#include <X11/keysym.h>
#include "mlx.h"
#include <X11/X.h>
#include <stdio.h>

typedef struct s_form
{
	int	x;
	int	y;
	int	l;
	int	color;
}	t_form;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
}	t_data;

void	draw(t_img *img, int x, int y, int color)
{
	char *put;

	put = img->addr + (y * img->line_len + x * img->bpp / 8);
	*(int *)put = color;
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 900)
	{
		j = 0;
		while (j < 600)
			draw(img, j++, i, color);
		++i;
	}
}

int	triangle(t_img *img, t_form my_form)
{
	int	i;
	int	j;

	i = 0;
	while (i < my_form.l)
	{
		j = my_form.x - i;
		while (j < my_form.x + i)
		{
			
			draw(img, j, my_form.y + i, my_form.color);
			j++;
		}
		i++;
	}
	return (0);
}

int	release(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (0);
	}
	printf("key release : %d\n", key);
	return (0);
}

int	press(int key, t_data *data)
{
	printf("key press : %d\n", key);
	return (0);
}

int	call_triangle(t_data *data)
{
	void	*test_img;
	int	img_width;
	int	img_height;

	render_background(&data->img, 0XFFFFFF);
	//test_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/bastien.xpm", &img_width, &img_height);
	triangle(&data->img, (t_form){200, 200, 100, 0XFF00FF});
	triangle(&data->img, (t_form){400, 400, 100, 0X00FFFF});
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.mlx_img, 0, 0);
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, test_img, 64, 0);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 900, "yes");
	if (!data.mlx_win)
		return (free(data.mlx_ptr), 1);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, 600, 900);

	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);

	
	mlx_loop_hook(data.mlx_ptr, &call_triangle, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &press, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &release, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
