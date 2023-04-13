/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/12 14:40:14 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

/*
	Used for user input
*/
static void	input_check(int ac, char **av)
{
	int	error;

	error = 0;
	if (ac == 3)
	{
		if (ft_atoi(av[1]) < 800 || ft_atoi(av[1]) > 1920)
			error = 1;
		if ((ft_strncmp("Mandelbrot", av[2], 11) * \
		ft_strncmp("Julia", av[2], 5)) != 0)
			error = 1;
	}
	else
		error = 1;
	if (error == 1)
	{
		ft_printf("%sInvalid arguments \n	---= Program takes: =---\n\
	[1] - window resolution ( x =< 1920 & x >= 800)\n\
	[2] - type of fractol   ( \"Mandelbrot\" or \"Julia\")%s\n", ERROR, NC);
		exit (error);
	}
}

// static t_fract	*mlx_setup(char **av)
// {
// 	t_fract	*vars;

// 	vars = (t_fract *)malloc(sizeof(t_fract));
//	vars->mlx_ptr = mlx_init();
// 	vars->width = (double)ft_atoi(av[1]);
// 	vars->height = (double)round(vars->width / 1.77);
// 	vars->fractal = av[2];
// 	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->width, vars->height, \
// 									vars->fractal);
// 	vars->img_ptr = mlx_new_image(vars->mlx_ptr, vars->width, \
// 									vars->height);
// 	vars->img_data_addr = mlx_get_data_addr(vars->img_ptr, \
// 		&vars->bits_per_pixel, &vars->line_length, &vars->endian);
// 	return (vars);
// }

int	main(int ac, char *av[])
{
	t_fract	*vars;
	// input_check(ac, av);
	vars->mlx_ptr = mlx_init();
	vars->width = (double)ft_atoi(av[1]);
	vars->height = (double)round(vars->width / 1.77);
	vars->fractal = av[2];
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->width, vars->height, \
									vars->fractal);
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, vars->width, \
									vars->height);
	return (0);
}
