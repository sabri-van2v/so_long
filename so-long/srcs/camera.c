#include "so_long.h"

void	copy_str(char *str, char *modified_str, int first, t_coordonees start)
{
	int	write_x;
	int	write_y;
	int	max;
	int	step_x;

	write_x = start.x;
	write_y = start.y;
	step_x = 0;
	max = 29;
	while (str[write_x++] != '\n')
		step_x++;
	if (step_x < 29)
		max = step_x;
	step_x = 0;
	while (first < (int)ft_strlen(str) && write_y < 15)
	{
		while (step_x < max)
		{
			modified_str[step_x] = str[first];
			step_x++;
			first++;
		}
		write_y++;
		first += start.len + 1;
	}
	modified_str[first] = '\0';
}

int	found_start_y(char *str)
{
	int	y;
	int	step;
	int	len;
	int	check;

	y = 0;
	step = 0;
	len = 0;
	while (str[y] != 'P')
		y++;
	check = y;
	while (str[len] != '\n')
		len++;
	while (check < (int)ft_strlen(str))
		check += len + 1;
	while (8 - --check > 0)
		step--;
	while (y - len - 1 > -1 && ++step < 8)
		y -= len + 1;
	return (y);
}

int	found_start_x(char *str)
{
	int	x;
	int	step;
	int	len;
	int	check;

	x = 0;
	step = 0;
	len = 0;
	while (str[x] != 'P')
		x++;
	check = x;
	while (str[check] != '\n')
		check++;
	while (16 - --check > 0)
		step--;
	while (x - )
	while (x - 1 > -1 && ++step < 8)
		x--;
	return (x);
}

void	new_camera(char *str, char *modified_str)
{
	t_coordonees	start;
	int				first;

	start.x = found_start_x(str);
	start.y = found_start_y(str);
	printf("x : %d\n", start.x);
	printf("y : %d\n", start.y);
	start.len = 0;
	while (str[start.len] != '\n')
		start.len++;
	first = start.x + (start.y * start.len);
	copy_str(str, modified_str, first, start);
}

char	*camera(char *str, t_data data)
{
	char			*modified_str;
	t_dimensions	camera;

	if (data.settings.width == 1856)
		camera.width = 29;
	else
		camera.width = data.settings.width / 64;
	if (data.settings.height == 960)
		camera.height = 15;
	else
		camera.width = data.settings.height / 64;
	modified_str = malloc(camera.width * (camera.height + 1));
	if (!modified_str)
		return (NULL);
	new_camera(str, modified_str);
	printf("%s\n", modified_str);
	return (modified_str);
}
