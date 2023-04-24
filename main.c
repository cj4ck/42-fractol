/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/21 16:21:01 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

//!		---=[ parsing.c ]=---
void	ft_input_check (t_data *data, int ac, char **av)
{
	if (ac == 3)
	{
		data->win_width = (double)ft_atoi(av[1]);
		data->win_height = (double)round(data->win_width); // / 1.77
		data->win_title = av[2];
	}
}
//!		---=[ setup.c ]=---

t_data	*ft_init(int ac, char **av)
{
	t_data	*data;
	data = (t_data *)malloc(sizeof(t_data));
	
	ft_input_check(data, ac, av);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, data->win_title);
	return (data);
}

//!		---=[ hooks.c ]=---
static int ft_key_press_hook(int keycode, t_data *data)
{
    if (keycode == KEY_ESCAPE)
	{
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
    return (0);
}

int main(int ac, char *av[])
{
	t_data	*data;
	data = ft_init(ac, av);
	ft_image_processing(data);
	ft_mandelbrot(data);
    mlx_key_hook(data->win_ptr, ft_key_press_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}