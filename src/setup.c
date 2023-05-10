/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:16:04 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 18:43:58 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Fractal init function
 * @param main Used to select fractal type and color palette.
 */
void	start_fractal(t_env *main)
{
	t_env	e;

	ft_memset(&e, 0, sizeof(e));
	e.win_title = main->win_title;
	e.fractal_type = main->fractal_type;
	e.color_palette = main->color_palette;
	set_mlx(&e);
	set_env(&e);
	set_color_palette(&e);
	e.draw(&e);
	mlx_key_hook(e.win, keyboard, &e);
	mlx_hook(e.win, 17, 0L << 0, win_destroy, &e);
	mlx_hook(e.win, 5, 1L << 3, mouse_release, &e);
	mlx_mouse_hook(e.win, mouse_press, &e);
	mlx_loop(e.mlx);
}

/**
 * @brief Set the MLX
 */
void	set_mlx(t_env *e)
{
	e->img_width = WIN_WIDTH;
	e->img_height = WIN_HEIGHT;
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		ft_error(e, "Failed to initialize MLX", 0);
	e->win = mlx_new_window(e->mlx, e->img_width, e->img_height, e->win_title);
	if (e->win == NULL)
		ft_error(e, "Failed to initialize window", 0);
	e->img = mlx_new_image(e->mlx, e->img_width, e->img_height);
	if (e->img == NULL)
		ft_error(e, "Failed to initialize new MLX image", 0);
	e->img_addr = mlx_get_data_addr(e->img, &e->img_bpp, &e->img_line_length,
			&e->img_endian);
	e->img_bytespp = e->img_bpp / 8;
}

/**
 * @brief Set the env vars
 */
void	set_env(t_env *e)
{
	set_default(e);
	if (e->fractal_type == '1')
	{
		e->fractal = mandelbrot;
		set_vars_brot(e);
	}
	else if (e->fractal_type == '2')
		e->fractal = julia;
	else if (e->fractal_type == '3')
		e->fractal = burningship;
	else if (e->fractal_type == '4')
	{
		e->fractal = julia;
		e->julia_x = -0.162;
		e->julia_y = 1.04;
	}
	else
		set_env2(e);
}

void	set_env2(t_env *e)
{
	if (e->fractal_type == '5')
	{
		e->fractal = julia;
		e->julia_x = -1.476;
		e->julia_y = 0;
	}
	else if (e->fractal_type == '6')
	{
		e->fractal = julia;
		e->julia_x = -0.4;
		e->julia_y = -0.59;
	}
	else if (e->fractal_type == '7')
	{
		e->fractal = julia;
		e->julia_x = -1.05;
		e->julia_y = 0.27;
	}
	else
		my_exit(e, 1);
}

/**
 * @brief Set the vars to default.
 * x axis is taken as fixed axis for window calc. 
 * x axis 0 is moved to the right for mandelbrot, therefore
 * x_max should be (around) 0.5 * abs(x_min)
 * y axis is evenly divided, therefore y min and max are half
 * of the range of x. but img ratio has to be taken into account
 * so we have to multiply that with (width/height) to not get
 * distorted images when using not square image dimensions.
 */
void	set_default(t_env *e)
{
	e->x_min = -2.0;
	e->x_max = -e->x_min;
	e->x_range = e->x_max - e->x_min;
	e->y_min = -(e->x_range) / 2 * e->img_height / e->img_width;
	e->y_max = (e->x_range) / 2 * e->img_height / e->img_width;
	e->y_range = e->y_max - e->y_min;
	e->max_iter = 500;
	e->min_iter = 20;
	e->iter = 160;
	e->iterstep = 20;
	e->zoom_current = 0;
	e->movefactor = 0.1;
	e->julia_x = -0.79;
	e->julia_y = 0.15;
	e->i = 0;
	e->draw = draw_pxl;
	e->inside_set = white;
	e->inside_set_str = "white";
	e->outside_set = solid;
	e->outside_set_str = "solid";
	e->hud_color = 0xFFFFFFFF;
	calc_xyranges(e);
}
