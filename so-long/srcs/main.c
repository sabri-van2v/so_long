#include "so_long.h"

int	main(int argc, char **argv)
{
	char			*str;
	t_dimensions	size;

	str = NULL;
	if (argc != 2)
		return (printf("Error\n"), 1);
	str = get_map(argv[1]);
	size = parsing(str);
	build_map(str, size);
	hooks();
	delete();
}