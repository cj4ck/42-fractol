/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:02:48 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/21 11:48:46 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/inc/libft.h"
# include "./minilibx_mms_20191025_beta/mlx.h"
// # include "./keymacros.h"
# include <math.h>

//	---= ft_printf Macros =---
# define ERROR "\033[0;31m!ERROR | "
# define GREEN "\033[1;32m"
# define NC "\033[0m"

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_SCROLL_RIGHT 6
# define MOUSE_SCROLL_LEFT 7

# define KEY_ESCAPE 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 22
# define KEY_R 15
# define KEY_PLUS 30
# define KEY_MINUS 44

# define MANDELBROT 990
# define JULIA 991
# define BURNING_SHIPS 992

// ---= structs =---
typedef	struct	s_parsing {

}	t_parsing;
typedef struct s_data {
	char	*win_title;
	int		win_width;
	int		win_height;

	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_ptr2;
	void			*win_ptr2;

	double		r_c;
	double		i_c;
	double		i_z;
	double		r_z;
	double		x;
	double		y;
	
	double		temp;
	double		it;

	void			*img_ptr;
	char			*img_addr;
	int		bits_per_pixel;
	int		line_length;

	int		endian;
}	t_data;

//	---=[ main.c ]=---

//	---=[ parsing.c ]=---

//	---=[ setuo.c ]=---
t_data	*ft_init(int ac, char **av);

//	---=[ color.c ]=---
//	---=[ hooks.c ]=---
//	---=[ mandelbrot.c ]=---
void	ft_mandel_calc_c(t_data *env);
void	ft_mandel_calc_z(t_data *env);
void	ft_mandelbrot(t_data *env);

//	---=[ image_processing.c ]=---
void	my_mlx_pixel_put(t_data *env, int color);
void    ft_image_processing(t_data *data);


#endif
