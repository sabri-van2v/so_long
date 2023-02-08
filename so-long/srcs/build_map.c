#include "so_long.h"

void	delete_str(char **str)
{
	char	*tmp;

	tmp = *str;
	*str = NULL;
	free(tmp);
}

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

void	build_map(char **str_full, t_data data)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	i = -1;
	x = 0;
	y = 0;
	str = NULL;
	if (data.settings.height == 960 || data.settings.width == 1856)
		str = camera(*str_full, data);
	else
		str = *str_full;
	if (!str)
		return (delete_str(str_full));
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
	if (data.settings.height == 960 || data.settings.width == 1856)
		free(str);
}