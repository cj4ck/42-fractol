/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:54 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 18:45:15 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Parses input and creates instance of home window unless we specyfied in
 * the arguemnts what exact kind of fractal we want. Then it calls that fractal
 * instead of creating home window.
 */
int	main(int ac, char **av)
{
	int		height;
	int		width;
	t_env	main;

	ft_memset(&main, 0, sizeof(main));
	input_check(&main, ac, av);
	parse(&main, av);
	main.mlx = mlx_init();
	if (!(main.mlx))
		ft_error(&main, "MLX INIT FAILED", -1);
	main.win = mlx_new_window(main.mlx, 1280, 720, \
"42Fract'ol project by cjackows");
	if (!(main.win))
		ft_error(&main, "MLX NEW WIN FAILED", 1);
	main.img = mlx_xpm_file_to_image(main.mlx, \
"./IMG/IMG.xpm", &width, &height);
	if (!main.img)
		ft_error(&main, "IMG IS MISSING", 1);
	mlx_put_image_to_window(main.mlx, main.win, main.img, 0, 0);
	mlx_key_hook(main.win, choose_fractal, &main);
	mlx_hook(main.win, 17, 0L << 0, win_destroy, &main);
	mlx_loop(main.mlx);
	return (0);
}

/**
 * @brief Main gate for fractal rendering initialization functions, based 
 * on the key pressed during home screen we are calling func responsible for 
 * fractal rendering. 
 * 
 * @param keycode Keycodes are passed during compilation because they
 * 	may differ on different OS.
 * @param main We need to acces this struct in order to pass information
 * about fractal that we are rendering efficently.
 */
int	choose_fractal(int keycode, t_env *main)
{
	if (keycode == KEY_ESC)
		my_exit(main, 0);
	else if (keycode == KEY_1)
	{
		main->fractal_type = '1';
		main->win_title = "Famous Mandelbrot set by Benoit Mandelbrot";
		start_fractal(main);
	}
	else if (keycode == KEY_2)
	{
		main->fractal_type = '2';
		main->win_title = "Alluring Julia set by Gaston Julia #1";
		start_fractal(main);
	}
	else if (keycode == KEY_3)
	{
		main->fractal_type = '3';
		main->win_title = "Burning Ship set by Michael Michelitsch and Otto E";
		start_fractal(main);
	}
	else
		choose_fractal2(keycode, main);
	return (0);
}

/**
 * @brief More Julia!
 */
int	choose_fractal2(int keycode, t_env *main)
{
	if (keycode == KEY_4)
	{
		main->fractal_type = '4';
		main->win_title = "Alluring Julia set #2 Dimensional Rift";
		start_fractal(main);
	}
	else if (keycode == KEY_5)
	{
		main->fractal_type = '5';
		main->win_title = "Alluring Julia set #3 Anemone";
		start_fractal(main);
	}
	else if (keycode == KEY_6)
	{
		main->fractal_type = '6';
		main->win_title = "Alluring Julia #4 Space Station";
		start_fractal(main);
	}
	else if (keycode == KEY_7)
	{
		main->fractal_type = '7';
		main->win_title = "Alluring Julia #5 Slightest Touch";
		start_fractal(main);
	}
	return (0);
}

/**
 * @brief For hook takes only one parameter in func.
 */
int	win_destroy(t_env *e)
{
	my_exit(e, 0);
	return (0);
}

/**
 * @brief Custom exit function to exit properly without leaks.
 */
int	my_exit(t_env *e, int failure)
{
	if (failure == -1)
	{
		exit(EXIT_FAILURE);
	}
	if (!failure)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_SUCCESS);
	}
	if (failure == 1)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_FAILURE);
	}
	return (0);
}
