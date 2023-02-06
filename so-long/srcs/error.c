#include "so_long.h"

void	error_get_map(int fd, char *str1, char *str2)
{
	close(fd);
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	printf("Error m\n");
	exit(1);
}

void	error_parsing(char *str)
{
	if (str)
		free(str);
	printf("Error p\n");
	exit(1);
}

void	error_build_game(char *str, t_data *data)
{
	int	i;

	i = 8;
	if (str)
		free(str);
	if (data->mlx_win && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->xpm && data->mlx_ptr)
	{
		while (--i > 0)
			mlx_destroy_image(data->mlx_ptr, data->xpm[i]);
		free(data->xpm);
	}
	if (data->mlx_ptr)
		(mlx_destroy_display(data->mlx_ptr), free(data->mlx_ptr));
	printf("Error b\n");
	exit(1);
}