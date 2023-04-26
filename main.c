/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/26 14:48:17 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

//!		---=[ parsing.c ]=---
/**
 * @brief Parses command line arguments and sets the window width, height, and title.
 * 
 * @param data A pointer to the main data struct.
 * @param ac The number of command line arguments.
 * @param av An array of strings representing the command line arguments.
 */
void	ft_parse (t_data *data, int ac, char **av)
{
	//** ---=[WIP]=---
	//?	[ ]  Windows dimentions
	//?	[ ]  Title == Fractal set
	//?	[ ]  Additional settings
	//?			[ ] Autozoom?
	//?			[ ] Psychodelic effects?
	//?			[ ] Multiple windows?
	if (ac == 3)
	{
		data->win_width = (double)ft_atoi(av[1]);
		data->win_height = (double)round(data->win_width); // / 1.77
		data->win_title = av[2];
	}
}

void	

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
		printf("%sError: Failed to initialize new window%s\n", ERROR, NC);
		exit (EXIT_FAILURE);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, data->win_title);
	if (data->win_ptr == NULL)
    {
		printf("%sError: Failed to initialize new window%s\n", ERROR, NC);
		exit (EXIT_FAILURE);
    }
	return (data);
}

//!		---=[ hooks.c ]=---
static int ft_key_press_hook(int keycode, t_data *data)
{
    if (keycode == KEY_ESCAPE)
	{
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (EXIT_SUCCESS);
	}
    return (0);
}

//!		---=[ main.c ]=---
int main(int ac, char *av[])
{
	t_data	*data;
	data = ft_init(ac, av);
	ft_image_init(data);
	// ft_mandelbrot(data);
    mlx_key_hook(data->win_ptr, ft_key_press_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}