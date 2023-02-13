#include "so_long.h"

void	check_walls(char *str, t_flags *flags)
{
	int	i;
	int	line_size;

	i = -1;
	flags->walls = 0;
	while (str[++i] != '\n' && str[i])
		if (str[i] != '1')
			error_parsing(str);
	line_size = i;
	while (str[++i + line_size + 1])
		if (str[i] == '\n' && (str[i - 1] != '1' || str[i + 1] != '1'))
			error_parsing(str);
	while (str[++i] != '\n' && str[i])
		if (str[i] != '1')
			error_parsing(str);
	flags->walls = 1;
}

void	check_form(char *str, t_flags *flags, t_dimensions *size)
{
	int	i;
	int	j;
	int	line_size;

	i = 0;
	line_size = 0;
	flags->rectangular = 0;
	while (str[line_size] != '\n' && str[line_size])
		line_size++;
	size->width = line_size;
	while (str[i])
	{
		j = 0;
		size->height++;
		while (str[i] != '\n' && str[i])
		{
			i++;
			j++;
		}
		if (j != line_size)
			error_parsing(str);
		if (str[i])
			i++;
	}
	flags->rectangular = 1;
}

void	check_chars(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	flags->position = 0;
	flags->collector = 0;
	flags->exit = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == 'N' || str[i] == '\n')
			;
		else if (str[i] == 'P')
		{
			flags->position++;
			flags->player = i;
		}
		else if (str[i] == 'C')
			flags->collector++;
		else if (str[i] == 'E')
			flags->exit++;
		else
			error_parsing(str);
		i++;
	}
}

t_dimensions	parsing(char *str)
{
	t_flags			flags;
	t_dimensions	size;

	size.height = 0;
	check_chars(str, &flags);
	if (flags.position != 1 || flags.exit != 1 || flags.collector < 1)
		error_parsing(str);
	check_form(str, &flags, &size);
	if (size.height > 18 || size.width > 34)
		error_parsing(str);
	check_walls(str, &flags);
	check_path(str, flags, size);
	return (size);
}