/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/29 11:57:40 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

//!		---=[ parsing.c ]=---

void	ft_input_check(t_data *data, int ac, char **av)
{
	if (ac < 2 || ac > 4)
		ft_exit(data, 1);
	if (!ft_strchr("MJB", (int)av[1][0]))
		ft_exit(data, 1);
	// if (!ft_strchr("RGBD", (int)av[2][0]))
		// ft_exit(data, 1);
	// if (av[1][0] == 'J')
	// 	check_julia(e, ac, av);
	// else if (ac != 3)
	// 	ft_exit(data, 1);
}

/**
 * @brief Parses command line arguments and 
 * sets the window width, height, and title.
 *
 * @param data A pointer to the main data struct.
 * @param ac The number of command line arguments.
 * @param av An array of strings representing the command line arguments.
 */
void ft_parse(t_data *data, int ac, char **av)
{
	//** ---=[WIP]=---
	//?//	[ ]  Windows dimentions
	//?	[X]  Title == Fractal set
	//?	[ ]  Additional settings
	//?			[ ] Autozoom?
	//?			[ ] Psychodelic effects?
	if (ac < 2 || ac > 4)
		ft_exit(data, 1);
	if (!ft_strchr("MJB", (int)av[1][0]))
		ft_exit(data, 1);
	//* data->win_width = (double)ft_atoi(av[1]); //CUSTOM RESOLUTION
	//* data->win_height = (double)round(data->win_width) / 1.77;
	data->win_title = av[1];
}

//!		---=[ init.c ]=---
/**
 * @brief  Initializes MLX and creates new window.
 *
 * @param ac Number of command line arguments
 * @param av Array of command line argument strings
 *
 * @return t_data* 	Returns a pointer to a initialized t_data struct.
 */
t_data	*ft_init(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	ft_parse(data, ac, av);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf("%sFailed to initialize MLX%s\n", ERROR, NC);
		exit (EXIT_FAILURE);
	}
	data->win_width = 1089;
	data->win_height = 580;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, \
	data->win_height, data->win_title);
	if (data->win_ptr == NULL)
	{
		ft_printf("%sFailed to initialize new window%s\n", ERROR, NC);
		exit (EXIT_FAILURE);
	}
	return (data);
}

//!		---=[ hooks.c ]=---
static int	ft_key_press_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
	{
		ft_exit(data, 0);
	}
	return (0);
}

int	ft_exit(t_data *data, int failure)
{
	int		fd;
	char	text[1500];
	int		readsize;

	if (failure)
	{
		fd = open("help.txt", 0);
		ft_printf("%s", ERROR);
		readsize = read(fd, text, 41);
		write(1, text, readsize);
		ft_printf("%s", NC);
		readsize = read(fd, text, 500);
		write(1, text, readsize);
		ft_printf("\n	\e[0;31mRed: \"R\", \e[0;32mGreen: \"G\", \
\e[0;34mBlue: \"B\", \e[38;5;242mDark \"D\"");
		write(1, "\n", 1);
		exit(EXIT_FAILURE);
		free(data);
	}
	else
	{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	}
	exit(EXIT_SUCCESS);
}

void	ft_fractal_type(t_data *data, char **av)
{
	
}

//!		---=[ main.c ]=---
int main(int ac, char *av[])
{
	t_data *data;
	
	data = ft_init(ac, av);
	// ft_image_init(data);
	// ft_mandelbrot(data);
	mlx_key_hook(data->win_ptr, ft_key_press_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}