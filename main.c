/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/29 09:53:13 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

//!		---=[ parsing.c ]=---

void	ft_input_check(t_data *data, int ac, char **av)
{
	if (ac < 2 || ac > 4 || (av[1][0] != 'S' && ac < 3))
		my_exit(data, 1);
	if (av[1][1] || !ft_strchr("MJBNS", (int)av[1][0]))
		my_exit(data, 1);
	if (av[1][0] == 'S')
		return ;
	if (av[2][1] || !ft_strchr("RGBD", (int)av[2][0]))
		my_exit(data, 1);
	// if (av[1][0] == 'J')
	// 	check_julia(e, ac, av);
	else if (ac != 3)
		my_exit(data, 1);
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
	//?	[ ]  Windows dimentions
	//?	[ ]  Title == Fractal set
	//?	[ ]  Additional settings
	//?			[ ] Autozoom?
	//?			[ ] Psychodelic effects?
	//?			[ ] Multiple windows?
	ft_input_check(data, ac, av);
	data->win_width = (double)ft_atoi(av[1]);
	data->win_height = (double)round(data->win_width) / 1.77;
	data->win_title = av[2];
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
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	return (0);
}

int	my_exit(t_data *data, int failure)
{
	int		fd;
	char	text[1500];
	int		readsize;
	int		discard;

	if (failure)
	{
		ft_printf("%s", ERROR);
		fd = open("help.txt", 0);
		readsize = read(fd, text, 1500);
		discard = write(1, text, readsize);
		discard = write(1, "\n", 1);
		exit(1);
	}
	else
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	discard = write(1, "Exit.\n", 6);
	(void)discard;
	exit(EXIT_SUCCESS);
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