#include "so_long.h"

int	line_after_player(char *str, int start)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i] != 'P')
		i++;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	if (str[i - 1] == '\n')
		n--;
	return (n);
}

int	start_str(char *str, int count)
{
	int	i;
	int	step;

	i = 0;
	step = 0;
	while (str[i] != 'P')
		i++;
	while (step < 15 && str[i] != '\n' && i > -1)
	{
		i--;
		step++;
	}
	if (str[i] == '\n')
		i++;
	step = 0;
	while (step < 8 && i - count - 1 > -1)
	{
		i -= count + 1;
		step++;
	}
	if (step == 8 && i - count - 1 > -1)
		i -= (count + 1) * line_after_player(str, i);
	return (i);
}

void	new_str(char *str, char *modified_str, t_dimensions camera)
{
	int	start;
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[count] != '\n')
			count++;
	start = start_str(str, count);
	if (count > 29)
	{
		while (i < camera.height * (camera.width + 1))
		{
			ft_strlcpy(&modified_str[i], &str[start], 30);
			start += count + 1;
			i += 30;
			modified_str[i - 1] = '\n';
		}
	}
	else
		ft_strlcpy(&modified_str[i], &str[start], 451);
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
	new_str(str, modified_str, camera);
	printf("%s\n", modified_str);
	return (modified_str);
}
