/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:39:01 by svan-de-          #+#    #+#             */
/*   Updated: 2023/02/13 20:39:01 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_steps(t_data *data, char c)
{
	static int	step = 0;
	char		*str;

	if (c == '+')
	{
		step++;
		ft_printf("%d\n", step);
	}
	str = ft_itoa(step);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 64, 64, 0, str);
	free(str);
}
