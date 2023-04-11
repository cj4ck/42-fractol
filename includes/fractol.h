/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:02:48 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/11 16:25:08 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./keymacros.h"
# include <math.h>

//	---= ft_printf Macros =---
#define ERROR "\033[0;31m!ERROR | "
#define GREEN "\033[1;32m"
#define NC "\033[0m"

#define MANDELBROT_VARS 
{
	std_vars->x = 0;
	std_vars->y = 0;
	std_vars->max_it = 40;
	std_vars->r_orgn = -0.5;
	std_vars->i_orgn = 0;
	std_vars->r_range = 4;
	std_vars->i_range = 2.5;
	std_vars->div_color = 0;
	std_vars->conv_color = 0;
	std_vars->zoom_factor = 2;
	std_vars->zoom_step = 1;
	std_vars->prime_color = 18;
}

#define JULIA
{
	std_vars->x = 0;
	std_vars->y = 0;
	std_vars->r_c = 0;
	std_vars->i_c = 0;
	std_vars->max_it = 40;
	std_vars->r_orgn = 0;
	std_vars->i_orgn = 0;
	std_vars->r_range = 4;
	std_vars->i_range = 2.5;
	std_vars->div_color = 0;
	std_vars->conv_color = 0;
	std_vars->zoom_factor = 2;
	std_vars->zoom_step = 1;
	std_vars->prime_color = 18;
}

typedef struct s_fract {
	void			*mlx_ptr;
	void			*win_ptr;
	char			*fractal; //name of fractal

	void			*img_ptr;
	char			*img_data_addr;
	// int				fractal_int;
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
