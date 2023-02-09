#include "so_long.h"

void	up(char *str, t_data *data, int player)
{
	//int	stock_height;
	//int	stock_width;

	printf("up\n");
	printf("\nstr before :\n%s\n", str);
	//mlx_destroy_image(data->mlx_ptr, data->xpm[2]);
	//data->xpm[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/bastien.xpm", &stock_height, &stock_width);
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[0], data->player.width * 64, data->player.height * 64);
	str[player] = '0';
	str[player - (data->settings.width / 64) - 1] = 'P';
	if (str[player - 1] == 'E')
		exit(0);
	delete_xpm(data);
	set_data_2(data);
	build_map(data->str, data);
	printf("\nstr after :\n%s\n", str);
	//data->player.height--;
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[2], data->player.width * 64, data->player.height * 64);
}

void	left(char *str, t_data *data, int player)
{
	//int	stock_height;
	//int	stock_width;

	printf("left\n");
	printf("\nstr before :\n%s\n", str);
	//mlx_destroy_image(data->mlx_ptr, data->xpm[2]);
	//data->xpm[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/bastien.xpm", &stock_height, &stock_width);
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[0], data->player.width * 64, data->player.height * 64);
	str[player] = '0';
	if (str[player - 1] == 'E')
		exit(0);
	str[player - 1] = 'P';
	delete_xpm(data);
	set_data_2(data);
	build_map(data->str, data);
	printf("\nstr after :\n%s\n", str);
	//data->player.width--;
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[2], data->player.width * 64, data->player.height * 64);
}

void	down(char *str, t_data *data, int player)
{
	//int	stock_height;
	//int	stock_width;

	printf("down\n");
	printf("\nstr before :\n%s\n", str);
	//mlx_destroy_image(data->mlx_ptr, data->xpm[2]);
	//data->xpm[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/bastien.xpm", &stock_height, &stock_width);
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[0], data->player.width * 64, data->player.height * 64);
	str[player] = '0';
	if (str[player - 1] == 'E')
		exit(0);
	str[player + (data->settings.width / 64) + 1] = 'P';
	delete_xpm(data);
	set_data_2(data);
	build_map(data->str, data);
	printf("\nstr after :\n%s\n", str);
	//data->player.height++;
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[2], data->player.width * 64, data->player.height * 64);
}

void	right(char *str, t_data *data, int player)
{
	//int	stock_height;
	//int	stock_width;

	printf("right\n");
	printf("\nstr before :\n%s\n", str);
	//mlx_destroy_image(data->mlx_ptr, data->xpm[2]);
	//data->xpm[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/bastien.xpm", &stock_height, &stock_width);
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[0], data->player.width * 64, data->player.height * 64);
	str[player] = '0';
	if (str[player - 1] == 'E')
		exit(0);
	str[player + 1] = 'P';
	delete_xpm(data);
	set_data_2(data);
	build_map(data->str, data);
	printf("\nstr after :\n%s\n", str);
	//data->player.width++;
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->xpm[2], data->player.width * 64, data->player.height * 64);
}