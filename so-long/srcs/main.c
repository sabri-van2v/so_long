#include "so_long.h"

int	main(int argc, char **argv)
{
	char			*str;
	t_dimensions	size;
	t_data			data;

	str = NULL;
	if (argc != 2)
		return (ft_printf("Error\n"), 1);
	str = get_map(argv[1]);
	size = parsing(str);
	set_data(&data, size);
	if (!data.xpm)
		error_build_game(str, &data);
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.settings.width, data.settings.height, "bastien_game");
	if (!data.mlx_win)
		error_build_game(str, &data);
	build_map(str, data);
	mlx_loop(data.mlx_ptr);
	//hooks();
	//delete();
}