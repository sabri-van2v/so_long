#include "so_long.h"

int	end(char *str, char *modified_str)
{
	int	i;
	int	len;
	int	count;
	int	len_line;

	i = 0;
	len_line = 0;
	count = 0;
	len = ft_strlen(str);
	while (str[len_line] != '\n' && str[len_line])
		len_line++;
	while (str[i] != 'P')
		i++;
	while (i < len && count < 7)
	{
		i += len_line + 1;
		count++;
	}
}

int	start(char *str, char *modified_str)
{}

char	*new_str(char *str, char *modified_str, t_dimensions camera)
{
	int	start;
	int	end;

	start = start(str, modified_str);
	end = end(str, modified_str);
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
	return (modified_str);
}