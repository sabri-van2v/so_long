/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:35:43 by svan-de-          #+#    #+#             */
/*   Updated: 2023/02/13 20:35:43 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_xpm(t_data *data)
{
	int	i;

	i = 7;
	if (data->xpm && data->mlx_ptr)
	{
		while (--i > -1)
			mlx_destroy_image(data->mlx_ptr, data->xpm[i]);
		free(data->xpm);
	}
}

void	delete_all(char *str, t_data *data)
{
	if (str)
		free(str);
	if (data->mlx_win && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	delete_xpm(data);
	if (data->mlx_ptr)
		(mlx_destroy_display(data->mlx_ptr), free(data->mlx_ptr));
}
