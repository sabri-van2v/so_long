#include "so_long.h"

void	build_map(char *str, t_dimensions size)
{
	t_data	data;

	data->xpm = NULL;
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (free(str), 1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, size.width, size.height);
	if (!data.mlx_win)
		return (free(str), free(data.mlx_ptr), 1);
}