/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/20 17:51:25 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

/*
!	Ignore for now, will do later
*/
// static int	ft_input_check (int ac, char **av)
// {
// 	int	error;
// 	error = 0;
// 	// if (ac == 3)
// 	// {
// 	// 	if (ft_atoi(av[1]) < 800 || ft_atoi(av[1]) > 1920)
// 	// 		error = 1;
// 	// 	if ((ft_strncmp("Mandelbrot", av[2], 11) * \
// 	// 	ft_strncmp("Julia", av[2], 5)) != 0)
// 	// 		error = 1;
// 	// }
// 	// else
// 	// 	error = 1;
// 	// if (error == 1)
// 	// {
// 	// 	ft_printf("%sInvalid arguments \n	---= Program takes: =---\n\
// 	// [1] - window resolution ( x =< 1920 & x >= 800)\n\
// 	// [2] - type of fractol   ( \"Mandelbrot\" or \"Julia\")%s\n", ERROR, NC);
// 	// 	exit (error);
// 	// }
// }

// int ft_rgb_to_int(double r, double g, double b)
// {
//     int color = 0;
//     color |= (int)(b * 255);
//     color |= (int)(g * 255) << 8;
//     color |= (int)(r * 255) << 16;
//     return (color);
// }

int	ft_end(t_fract *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	free(env);
	exit(1);
}

int	ft_keyboard_inout(int keycode, t_fract *env)
{
	if (keycode == 53)
		ft_end(env);
	return (0);
}

void	my_mlx_pixel_put(t_fract *env, int color)
{
	char	*dst;

	dst = env->img_addr + ((int)env->y * env->line_length + (int)env->x * (env->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_mandel_calc_c(t_fract *env)
{
	// ft_printf("x->%i\n", env->x);
	env->r_c = ((env->x / 1000) * 4) - (4 / 2) - 1;
	// ft_printf("rc->%i\n", env->r_c);
	env->i_c = ((-1) * (env->y / 1000) * 4) + (4 / 2) + 0;
	env->r_z = 0;
	// ft_printf("rc->%i\n", env->r_c);
	// ft_printf("ic->%i\n", env->i_c);
	env->i_z = 0;
	env->temp = 0;
	env->it = 0;
}

void	ft_mandel_calc_z(t_fract *env)
{
	env->temp = pow(env->r_z, 2) - pow(env->i_z, 2) + env->r_c;
	env->i_z = (2 * env->r_z * env->i_z) + env->i_c;
	env->r_z = env->temp;
	env->it++;
}

void	ft_mandelbrot(t_fract *env)
{
	env->temp = 0;
	env->x = 0; //top left corner 
	env->y = 0; 

	while (env->x < 1000)
	{
		while (env->y < 1000)
		{
			ft_mandel_calc_c(env);
				// ft_printf("z->%i\n", env->r_z);
			while (env->it < 20 && (sqrt(pow(env->r_z, 2) + pow(env->i_z, 2)) <= 2))
			{
				ft_mandel_calc_z(env);
				// ft_printf("it->%i\n", env->it);
				// ft_printf("z->%i\n", sqrt(pow(env->r_z, 2) + pow(env->i_z, 2)));				
			}
			if (env->it < 20)
				my_mlx_pixel_put(env, 0x00000000);
			else
			{
				// ft_printf("\ntest\n");
				my_mlx_pixel_put(env, 0x00FFFFFF);
			}
			env->y++;
		}
		env->y = 0;
		env->x++;
	}
	// ft_printf("z->%i\n", env->r_z);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

int main(int ac, char **av)
{
	t_fract	*env;
	t_fract	*env_2;

	// if (ft_input_check(ac, av) == 0)
	// 	return (0);
	env = (t_fract *)malloc(sizeof(t_fract));
	env_2 = (t_fract *)malloc(sizeof(t_fract));
    env->mlx_ptr = mlx_init();
	env_2->mlx_ptr = mlx_init();
    env->win_ptr = mlx_new_window(env->mlx_ptr, 1000, 1000, "Let's play around with it");
	env_2->win_ptr = mlx_new_window(env_2->mlx_ptr, 100, 100, "Color palette");
	// int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
	// mlx_pixel_put(env->mlx_ptr, env->win_ptr, 1, 1, 0x2F6AFF);
	env->img_ptr = mlx_new_image(env->mlx_ptr, 1000, 1000);
	env->img_addr = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel, &env->line_length,
								&env->endian);
	env_2->img_ptr = mlx_new_image(env->mlx_ptr, 1000, 1000);
	env_2->img_addr = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel, &env->line_length,
								&env->endian);
								
	ft_mandelbrot(env);
	mlx_loop(env->mlx_ptr);
	mlx_loop(env_2->mlx_ptr);
	return (0);
}
