/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:13:17 by svan-de-          #+#    #+#             */
/*   Updated: 2023/02/03 07:32:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_flags
{
	int	position;
	int	player;
	int	collector;
	int	exit
	int rectangular;
	int	walls;
	int	path;
}	t_flags;

typedef struct s_dimensions
{
	int	width;
	int	height;
}	t_dimensions;

#endif