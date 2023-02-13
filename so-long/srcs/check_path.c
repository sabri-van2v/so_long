/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:35:33 by svan-de-          #+#    #+#             */
/*   Updated: 2023/02/13 20:35:33 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_collector(char *str, t_dimensions size)
{
	int	i;

	i = size.width;
	while (str[i + size.width])
	{
		if (str[i] == 'C')
			return (1);
		if (str[i] == 'E')
			if (str[i + 1] != '2' && str[i - 1] != '2'
				&& str[i + size.width + 1] != 2
				&& str[i + size.width - 1] != '2')
				return (1);
		i++;
	}
	return (0);
}

void	player_explores(char *str, t_flags *flags, t_dimensions size, char c)
{
	if (c == 'l')
	{
		str[flags->player] = '2';
		flags->player = flags->player - 1;
	}
	else if (c == 'r')
	{
		str[flags->player] = '2';
		flags->player = flags->player + 1;
	}
	else if (c == 'd')
	{
		str[flags->player] = '2';
		flags->player = flags->player + size.width + 1;
	}
	else if (c == 'a')
	{
		str[flags->player] = '2';
		flags->player = flags->player - size.width - 1;
	}
}

void	tracking(char *str, t_flags flags, t_dimensions size)
{
	int	stock;

	if (str[flags.player] == '1' || str[flags.player] == 'E')
		return ;
	stock = flags.player;
	if (str[stock - 1] == '0' || str[stock - 1] == 'C' || str[stock - 1] == 'N')
		(player_explores(str, &flags, size, 'l'), tracking(str, flags, size));
	flags.player = stock;
	if (str[stock + 1] == '0' || str[stock + 1] == 'C' || str[stock + 1] == 'N')
		(player_explores(str, &flags, size, 'r'), tracking(str, flags, size));
	flags.player = stock;
	if (str[stock + size.width + 1] == '0'
		|| str[stock + size.width + 1] == 'C'
		|| str[stock + size.width + 1] == 'N')
		(player_explores(str, &flags, size, 'd'), tracking(str, flags, size));
	flags.player = stock;
	if (str[stock - size.width - 1] == '0'
		|| str[stock - size.width - 1] == 'C'
		|| str[stock - size.width - 1] == 'N')
		(player_explores(str, &flags, size, 'a'), tracking(str, flags, size));
	if (str[stock] != '2')
		str[stock] = '2';
}

void	check_path(char *str, t_flags flags, t_dimensions size)
{
	char	*str_path;

	str_path = ft_strdup(str);
	if (!str_path)
		error_parsing(str);
	tracking(str_path, flags, size);
	if (no_collector(str_path, size) != 0)
		(free(str_path), error_parsing(str));
	free(str_path);
}
