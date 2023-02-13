#include "so_long.h"

int	isnt_wall(char c)
{
	if (c == '1' || c == '2')
		return (0);
	return (1);
}

void	sprite(char *str, t_data *data)
{
	int	i;
	static int	call = 0;

	call++;
	i = -1;
	if (call % 2 == 1)
	{
		while (str[++i])
			if (str[i] == '1')
				str[i] = '2';
	}
	else
	{
		while (str[++i])
			if (str[i] == '2')
				str[i] = '1';
	}
	delete_xpm(data);
	refresh_data(data);
	if (!data->xpm)
		error_build_game(str, data);
	build_map(data->str, data);
}

int	loop(t_data *data)
{
	static int	time = 0;

	time++;
	if (time == 10000)
	{
		sprite(data->str, data);
		time = 0;
	}
	return (0);
}

int	press(int key, t_data *data)
{
	int	player;

	player = 0;
	while (data->str[player] != 'P')
		player++;
	if (key == XK_Escape || key == 17)
		(delete_all(data->str, data), exit(0));
	if ((key == XK_w || key == XK_W) && isnt_wall(data->str[player - (data->settings.width / 64) - 1]))
		return (up(data->str, data, player), 1);
	if ((key == XK_a || key == XK_A) && isnt_wall(data->str[player - 1]))
		return (left(data->str, data, player), 1);
	if ((key == XK_s || key == XK_S) && isnt_wall(data->str[player + (data->settings.width / 64) + 1]))
		return (down(data->str, data, player), 1);
	if ((key == XK_d || key == XK_D) && isnt_wall(data->str[player + 1]))
		return (right(data->str, data, player), 1);
	return (0);
}

void	hooks(char *str, t_data *data)
{
	data->str = str;
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &press, data);
	mlx_hook(data->mlx_win, 17, (1L << 17), &cross_kill, data);
	mlx_loop_hook(data->mlx_ptr, &loop, data);
}