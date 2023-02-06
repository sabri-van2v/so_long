#include "so_long.h"

void	good_xpm(char c, t_data data, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.xpm[0], x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.xpm[1], x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.xpm[2], x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.xpm[3], x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.xpm[4], x * 64, y * 64);
	if (c == 'N')
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.xpm[5], x * 64, y * 64);
}

void	build_map(char *str, t_data data)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (str[++i])
	{
		x = 0;
		while (str[i] != '\n' && str[i])
		{
			good_xpm(str[i], data, x, y);
			x++;
			i++;
		}
		y++;
	}
}