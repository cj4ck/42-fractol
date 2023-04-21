/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/21 14:58:52 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

//		---=[ parsing.c ]=---
void	ft_input_check (t_data *data, int ac, char **av)
{
	if (ac == 3)
	{
		data->win_width = (double)ft_atoi(av[1]);
		data->win_height = (double)round(data->win_width); // / 1.77
		data->win_title = av[2];
	}
}
//		---=[ setup.c ]=---
t_data	*ft_init(int ac, char **av)
{
	t_data	*data;
	data = (t_data *)malloc(sizeof(t_data));
	
	ft_input_check(data, ac, av);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, data->win_title);
	return (data);
}

int main(int ac, char *av[])
{
	t_data	*data;
	data = ft_init(ac, av);
	ft_image_processing(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}