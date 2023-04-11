/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:02:48 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/11 15:01:51 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./keymacros.h"
# include <math.h>

#define ERROR "\033[0;31m!ERROR | "
#define GREEN "\033[1;32m"
#define NC "\033[0m"

typedef struct s_fract {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data_addr;
	char			*fractal;
	int				fractal_int;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			width;
	double			height;
	int				offset;
	double			zoom_factor;
	int				zoom_step;

	double			x;
	double			y;
	double			r_orgn;
	double			i_orgn;
	double			r_range;
	double			i_range;
	double			r_c;
	double			i_c;
	double			r_z;
	double			i_z;
	double			x_mouse_pos;
	double			y_mouse_pos;
	double			it;
	double			max_it;
	unsigned int	div_color;
	int				prime_color;
	int				hud_color;
	unsigned int	conv_color;
	double			temp;
}	t_fract;

//	---= main.c =---

#endif
