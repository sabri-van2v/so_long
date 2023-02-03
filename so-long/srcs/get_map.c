#include "so_long.h"

void	read_map(int fd, char *str)
{
	char	*tmp;
	char	*reader;

	tmp = malloc(1);
	reader = malloc(1);
	if (!tmp || !reader)
		error_get_map(fd, reader, tmp);
	tmp[0] = '\0';
	reader[0] = '\0';
	while (1)
	{
		free(reader);
		reader = get_next_line(fd);
		if (!reader)
			break ;
		str = ft_strjoin(tmp, reader);
		if (!str)
			error_get_map(fd, reader, tmp);
		free(tmp);
		tmp = str;
	}
	free(tmp);
	return (str);
}

char	*get_map(char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_get_map(-1, NULL, NULL);
	str = NULL;
	str = read_map(fd, str);
	if (!str || close(fd) == -1)
		error_get_map(fd, str, NULL);
	return (str);
}