/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:02:48 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/29 09:51:53 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/inc/libft.h"
# include "./minilibx_mms_20191025_beta/mlx.h"
// # include "./keymacros.h"
# include <math.h>

// *	---=[ Printf Macros ]=---
# define ERROR "\033[0;31m!ERROR: "
# define GREEN "\033[1;32m"
# define NC "\033[0m"

// ?	---=[ Hooks ]=---
//?		[ ]	Move them to makefile somehow
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

typedef struct s_data {
//*		---=[ MLX ]=---
	void	*mlx_ptr;	//*	Pointer to MLX instance */
	void	*win_ptr;	//*	Pointer to MLX window */
	char	*win_title;	//*	Pointer to window title */
	int		win_width;	//*	Height of image in pixels */
	int		win_height; //*	Height of window in pixels */

//*		---=[ Image processing ]=---
	void	*img_ptr;	//*	Pointer to MLX image */
	char	*img_data;	//*	Pointer to image data buffer */
	int		width;		//*	Width of image in pixels */
	int		height;		//*	Height of image in pixels */
	int		bpp;		//*	Number of bits per pixel */
	int		line_size;	//*	Number of bytes per line */
	int		endian;		//*	Endianness of pixel data */
	double	y; //?
	double	x; //?

//*		---=[ Fractol rendering ]=---
	double	i_c;
	double	r_c;
	double	i_z;
	double	r_z;
	double	temp;
	double	it;

}	t_data;

//*		---=[ main.c ]=---
int	my_exit(t_data *data, int failure);

//*		---=[ setup.c ]=---
t_data	*ft_init(int ac, char **av);

//*		---=[ image_processing.c ]=---
void	my_mlx_pixel_put(t_data *env, int color);
void	ft_image_processing(t_data *data);
unsigned char	**ft_image_buffer_init(unsigned char **buffer, t_data *data);

//*		---=[ color.c ]=---

//*		---=[ hooks.c ]=---

//*		---=[ mandelbrot.c ]=---
// void	ft_mandel_calc_c(t_data *env);
// void	ft_mandel_calc_z(t_data *env);
// void	ft_mandelbrot(t_data *env);

#endif
