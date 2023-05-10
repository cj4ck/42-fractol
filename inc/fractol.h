/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:19:46 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/04 17:19:46 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <libft.h>

// *	---=[ Printf Macros ]=---
#define ERROR " \e[48;5;160m[ ERROR ]\e[0m \e[38;5;196m\e[4m"
#define P_DEBUG " \e[48;5;202m              [ DEBUGGING ]            \e[0m"
#define T_DEBUG " \e[38;5;202m"
# define GREEN "\033[1;32m"
# define NC "\033[0m"
#define BOLD "\e[1m"
#define ITALIC "\e[3m"
#define UNDERLINE "\e[4m"
#define STRIKETHROUGH "\e[9m"
#define RED "\e[31m"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 780

typedef struct s_e
{
	void	*mlx;
	void	*win;
	char	*win_title;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_bytespp;
	int		img_line_length;
	int		img_endian;
	int		img_width;
	int		img_height;

	char	fractal_type;

	double	x_min;
	double	x_max;
	double	x_range;
	double	y_min;
	double	y_max;
	double	y_range;
	double	x_mappd;
	double	y_mappd;

	double	zoom_current;
	double	movefactor;
	int		i;

	int		mouse_press_x;
	int		mouse_press_y;
	int		mouse_release_x;
	int		mouse_release_y;
	int		mouse_button;

	int		max_iter;
	int		min_iter;
	int		iter;
	int		iterstep;

	double	julia_x;
	double	julia_y;

	double	r_start;
	double	r_min;
	double	a_mappd;
	double	b_mappd;
	double	r_mappd;
	double	factor;
	double	line;

	int		maxcolor;
	int		mincolor;
	int		mincolor_t;
	int		mincolor_r;
	int		mincolor_g;
	int		mincolor_b;
	int		maxcolor_t;
	int		maxcolor_r;
	int		maxcolor_g;
	int		maxcolor_b;

	char	color_palette;

	char	*inside_set_str;
	char	*outside_set_str;
	char	*color_palette_str;

	char	*current_outside_set;
	char	*current_inside_set;
	char	*current_zoom_str;
	char	*current_iter_str;
	char	*current_color_palette_str;

	int		hud_color;

	void	(*draw)();
	int		(*fractal)();
	int		(*outside_set)();
	int		(*inside_set)();
	char	*test;
}	t_env;

// // *	---=[ Debugging functions | debugging.c ]=---
// void	ft_debug(char *str, char*str2, t_env	*env);
// void	ft_debug_this(char	*str);

// *	---=[ Main | main.c ]=---
int		choose_fractal(int keycode, t_env *main);
int		choose_fractal2(int keycode, t_env *main);
int		my_exit(t_env *e, int failure);
int		win_destroy(t_env *e);
void	ft_error(t_env *e, char	*error_msg, int failure);

// *	---=[ Setup MLX and Vars | setup.c ]=---
void	start_fractal(t_env *e);
void	set_env(t_env *e);
void	set_env2(t_env *e);
void	set_mlx(t_env *e);
void	set_default(t_env *e);

// *	---=[ Set the mandelbrot vars | mandelbrot.c ]=---
void	set_vars_brot(t_env *e);

// *	---=[ Input processing | input_processing.c ]=---
void	input_check(t_env *e, int ac, char **av);
void	parse(t_env *e, char **av);

// *	---=[ Base colors settings | color_palette.c ]=---
void	set_color_palette_default(t_env *e);
void	set_color_palette(t_env *e);
void	set_color_palette2(t_env *e);
void	set_color_palette3(t_env *e);

// *	---=[ Displays overlay | overlay.c ]=---
void	ft_overlay(t_env *e);

// *	---=[ Pixel functions | pxl.c ]=---
void	draw_pxl(t_env *e);
void	map_pxl(t_env *e, int x, int y);
void	put_pixel(t_env *e, int x, int y, int color);

// *	---=[ Computes the fractal set | fractals_calculations.c ]=---
int		mandelbrot(t_env *e);
int		julia(t_env *e);
int		burningship(t_env *e);

// *	---=[ Returns color values based on coordinates | inside_set.c ]=---
int		black(int x, int y);
int		white(int x, int y);
int		web(int x, int y);
int		glitched(int x, int y);

// *	---=[ Returns color values based on coordinates | outside_set.c ]=---
int		solid(t_env *e, int n);
int		candy(t_env *e, int n);
int		doppler(t_env *e, int n);
int		bernstein(t_env *e, int n);
int		rev_bernstein(t_env *e, int n);

// *	---=[ Simple calculations | simple_calculations.c ]=---
void	calc_xyranges(t_env *e);
double	double_absolute(double n);
int		int_absolute(int n);

// *	---=[ Keyboard & Mouse input processing | hooks.c ]=---
int		keyboard(int keycode, t_env *e);
int		mouse_press(int button, int mouse_x, int mouse_y, t_env *e);
int		mouse_release(int button, int mouse_x, int mouse_y, t_env *e);
void	julia_shape(t_env *e, int keycode);
void	reset_values(t_env *e);

// *	---=[ Navigation | navigation.c ]=---
void	move_key(t_env *e, int direction);
void	move_mouse(t_env *e);
void	zoom(t_env *e, int zoom_in);

// *	---=[ Change outside set | change_set.c ]=---
void	change_inside_set(t_env *e);
void	change_outside_set(t_env *e);
void	change_outside_set2(t_env *e);

// *	---=[ Change inside set | change_color_palette.c ]=---
void	change_iter(t_env *e, int keycode);
void	change_color_palette(t_env *e);
void	change_color_palette2(t_env *e);
void	change_color_palette3(t_env *e);
#endif