#include "so_long.h"

void	up(char *str, t_data *data, int player)
{
	printf("up\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[0], data->player.width * 64, data->player.height * 64);
	str[player] = '0';
	
	str[player - (data->settings.width / 64) - 1] = 'C';
	data->player.height--;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[2], data->player.width * 64, data->player.height * 64);
}

void	left(char *str, t_data *data, int player)
{
	printf("left\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[0], data->player.width * 64, data->player.height * 64);
	str[player] = '0';
	str[player - 1] = 'C';
	data->player.width--;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[2], data->player.width * 64, data->player.height * 64);
}

void	down(char *str, t_data *data, int player)
{
	printf("down\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[0], data->player.width * 64, data->player.height * 64);
	str[player] = '0';
	str[player + (data->settings.width / 64) + 1] = 'C';
	data->player.height++;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[2], data->player.width * 64, data->player.height * 64);
}

void	right(char *str, t_data *data, int player)
{
	printf("right\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[0], data->player.width * 64, data->player.height * 64);
	str[player] = '0';
	str[player + 1] = 'C';
	data->player.width++;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[2], data->player.width * 64, data->player.height * 64);
}