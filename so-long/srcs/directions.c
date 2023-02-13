/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:36:01 by svan-de-          #+#    #+#             */
/*   Updated: 2023/02/13 22:09:53 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collector_found(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == 'C')
			return (1);
	return (0);
}

void	up(char *str, t_data *data, int player)
{
	if (str[player - (data->settings.width / 64) - 1] == 'E'
		&& !collector_found(str))
		(put_steps(data, '+'), ft_printf("VICTORY - Bastien can talk\n"),
			delete_all(str, data), exit(0));
	if (str[player - (data->settings.width / 64) - 1] == 'N')
		(put_steps(data, '+'), ft_printf("DEFEAT - Bastien is mute\n"),
			delete_all(str, data), exit(0));
	if (str[player - (data->settings.width / 64) - 1] == 'E'
		&& collector_found(str))
		return ;
	str[player] = '0';
	str[player - (data->settings.width / 64) - 1] = 'P';
	delete_xpm(data);
	refresh_data(data);
	if (!data->xpm)
		error_build_game(str, data);
	build_map(data->str, data);
	put_steps(data, '+');
}

void	left(char *str, t_data *data, int player)
{
	if (str[player - 1] == 'E' && !collector_found(str))
		(put_steps(data, '+'), ft_printf("VICTORY - Bastien can talk\n"),
			delete_all(str, data), exit(0));
	if (str[player - 1] == 'N')
		(put_steps(data, '+'), ft_printf("DEFEAT - Bastien is mute\n"),
			delete_all(str, data), exit(0));
	if (str[player - 1] == 'E' && collector_found(str))
		return ;
	str[player] = '0';
	str[player - 1] = 'P';
	delete_xpm(data);
	refresh_data(data);
	if (!data->xpm)
		error_build_game(str, data);
	build_map(data->str, data);
	put_steps(data, '+');
}

void	down(char *str, t_data *data, int player)
{
	if (str[player + (data->settings.width / 64) + 1] == 'E'
		&& !collector_found(str))
		(put_steps(data, '+'), ft_printf("VICTORY - Bastien can talk\n"),
			delete_all(str, data), exit(0));
	if (str[player + (data->settings.width / 64) + 1] == 'N')
		(put_steps(data, '+'), ft_printf("DEFEAT - Bastien is mute\n"),
			delete_all(str, data), exit(0));
	if (str[player + (data->settings.width / 64) + 1] == 'E'
		&& collector_found(str))
		return ;
	str[player] = '0';
	str[player + (data->settings.width / 64) + 1] = 'P';
	delete_xpm(data);
	refresh_data(data);
	if (!data->xpm)
		error_build_game(str, data);
	build_map(data->str, data);
	put_steps(data, '+');
}

void	right(char *str, t_data *data, int player)
{
	if (str[player + 1] == 'E' && !collector_found(str))
		(put_steps(data, '+'), ft_printf("VICTORY - Bastien can talk\n"),
			delete_all(str, data), exit(0));
	if (str[player + 1] == 'N')
		(put_steps(data, '+'), ft_printf("DEFEAT - Bastien is mute\n"),
			delete_all(str, data), exit(0));
	if (str[player + 1] == 'E' && collector_found(str))
		return ;
	str[player] = '0';
	str[player + 1] = 'P';
	delete_xpm(data);
	refresh_data(data);
	if (!data->xpm)
		error_build_game(str, data);
	build_map(data->str, data);
	put_steps(data, '+');
}
