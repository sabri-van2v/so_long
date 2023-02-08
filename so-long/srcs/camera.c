#include "so_long.h"

char	*new_str(char *str, char *modified_str, int size, int i)
{
	modified_str[size] = '\0';
	//printf("i : %d\n, size : %d\n", i, size);
	while (--size > -1 && --i > -1)
		modified_str[size] = str[i];
	
	if (i != 0 || size != 0)
		return (delete_str(&modified_str), NULL);
	return (modified_str);
}

int	numbers_of_lines(char *str, int *i)
{
	int	lines;

	lines = 0;
	while (lines < 8 && (*i) > -1)
	{
		if (str[(*i)] == '\n')
			lines++;
		(*i)--;
	}
	(*i)++;
	lines = 0;
	while (lines < 16 && str[(*i)])
	{
		if (str[(*i)] == '\n')
			lines++;
		(*i)++;
	}
	if (str[(*i)] == '\0')
		lines++;
	return (lines);
}

int	numbers_of_columns(char *str, int *i)
{
	int	columns;
	int	columns_tot;

	columns = 0;
	columns_tot = 0;
	while (str[columns_tot] != '\n' && str[columns_tot])
		columns_tot++;
	columns_tot--;
	while (str[(*i)] != '\n' && (*i) > -1)
			(*i)--;
	if (str[(*i)] == '\n')
		(*i)++;
	while (str[(*i)] != '\n' && str[(*i)])
	{
		columns++;
		(*i)++;
	}
	return (columns);
}

char	*camera(char *str, t_data data)
{
	char	*modified_str;
	int		i;
	t_dimensions	camera;

	i = 0;
	while (str[i] != 'P')
		i++;
	printf("i (p) : %d\n", i);
	if (data.settings.width == 1920)
		camera.width = numbers_of_columns(str, &i);
	else
		camera.width = data.settings.width / 64;
	printf("i (w) : %d\n", i);
	printf("clolumns : %d\n", camera.width);
	if (data.settings.height == 1024)
		camera.height = numbers_of_lines(str, &i);
	else
		camera.width = data.settings.height / 64;
	printf("i (h) : %d\n", i);
	printf("lines : %d\n", camera.height);
	modified_str = malloc((camera.width + 1) * camera.height);
	if (!modified_str)
		return (NULL);
	modified_str = new_str(str, modified_str, ((camera.width + 1) * camera.height), i);
	if (!modified_str)
		return (NULL);
	return (modified_str);
}