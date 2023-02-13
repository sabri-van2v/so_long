#include "so_long.h"

void    put_steps(t_data *data, char c)
{
	static int	step = 0;
	char		*str;

	if (c == '+')
		step++;
	str = ft_itoa(step);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 64, 64, 0, str);
	free(str);
}