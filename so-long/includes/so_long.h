/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:13:17 by svan-de-          #+#    #+#             */
/*   Updated: 2023/02/13 23:26:27 by svan-de-         ###   ########.fr       */
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
	int	exit;
	int	rectangular;
	int	walls;
	int	path;
}	t_flags;

typedef struct s_dimensions
{
	int	width;
	int	height;
}	t_dimensions;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			**xpm;
	t_dimensions	settings;
	char			*str;
}	t_data;

void			error_get_map(int fd, char *str1, char *str2);

void			error_parsing(char *str);

void			error_build_game(char *str, t_data *data);

int				cross_kill(t_data *data);

void			delete_xpm(t_data *data);

void			delete_all(char *str, t_data *data);

void			put_steps(t_data *data, char c);

int				collector_found(char *str);

void			up(char *str, t_data *data, int player);

void			left(char *str, t_data *data, int player);

void			down(char *str, t_data *data, int player);

void			right(char *str, t_data *data, int player);

int				isnt_wall(char c);

void			sprite(char *str, t_data *data);

int				loop(t_data *data);

int				press(int key, t_data *data);

void			hooks(char *str, t_data *data);

void			good_xpm(char c, t_data *data, int i, int j);

void			build_map(char *str, t_data *data);

void			check_xpm(t_data *data);

void			set_xpm(t_data *data);

void			refresh_data(t_data *data);

void			set_data(t_data *data, t_dimensions size);

int				no_collector(char *str, t_dimensions size);

void			player_explores(char *str, t_flags *flags, t_dimensions size,
					char c);

void			tracking(char *str, t_flags flags, t_dimensions size);

void			check_path(char *str, t_flags flags, t_dimensions size);

void			check_walls(char *str, t_flags *flags);

void			check_form(char *str, t_flags *flags, t_dimensions *size);

void			check_chars(char *str, t_flags *flags);

t_dimensions	parsing(char *str);

void			check_leak(char *reader, char *tmp);

char			*read_map(int fd, char *str);

char			*get_map(char *file);

int				main(int argc, char **argv);

#endif