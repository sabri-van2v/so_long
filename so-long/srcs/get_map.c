/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:33:09 by svan-de-          #+#    #+#             */
/*   Updated: 2023/02/13 20:33:09 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_leak(char *reader, char *tmp)
{
	static int	flag = 0;

	flag++;
	if ((!reader || reader[0] == '\n') && tmp[0] == '\0' && flag == 1)
		free(tmp);
}

char	*read_map(int fd, char *str)
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
		check_leak(reader, tmp);
		if (!reader || reader[0] == '\n')
			break ;
		str = ft_strjoin(tmp, reader);
		if (!str)
			error_get_map(fd, reader, tmp);
		free(tmp);
		tmp = str;
	}
	free(reader);
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
