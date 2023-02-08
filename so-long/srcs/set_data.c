/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:24:01 by svan-de-          #+#    #+#             */
/*   Updated: 2023/02/08 15:41:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_xpm(t_data *data)
{
	int	i;

	i = 7;
	while (--i > -1)
	{
		if (!data->xpm[i])
		{
			i = 7;
			while (--i > -1)
				if (data->xpm[i])
					(mlx_destroy_image(data->mlx_ptr, data->xpm[i]), data->xpm[i] = NULL);
			free(data->xpm);
			break ;
		}
	}
}

void	set_xpm(t_data *data)
{
	int	stock_height;
	int	stock_width;

	data->xpm[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/map.xpm", &stock_height, &stock_width);
	data->xpm[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/arbre.xpm", &stock_height, &stock_width);
	data->xpm[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/bastien.xpm", &stock_height, &stock_width);
	data->xpm[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/kirby.xpm", &stock_height, &stock_width);
	data->xpm[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/medecine.xpm", &stock_height, &stock_width);
	data->xpm[5] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/micro.xpm", &stock_height, &stock_width);
	data->xpm[6] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/sprite.xpm", &stock_height, &stock_width);
	check_xpm(data);
}

void	set_data(t_data *data, t_dimensions size)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->xpm = NULL;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	if (size.height * 64 > 1024)
		data->settings.height = 1024;
	else
		data->settings.height = size.height * 64;
	if (size.width * 64 > 1920)
		data->settings.width = 1920;
	else
		data->settings.width = size.width * 64;
	data->xpm = malloc(sizeof(void *) * 7);
	if (!data->xpm)
		return ;
	set_xpm(data);
}