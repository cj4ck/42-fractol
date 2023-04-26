/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:54:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/24 14:01:20 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

/*
//** [WIP] <- NEEDS A LOT OF WORK
// void	ft_mandel_calc_c(t_data *data)
// {
// 	data->r_c = ((data->x / data->win_height) * 4) - (4 / 2) - 1;
// 	data->i_c = ((-1) * (data->y / data->win_width) * 4) + (4 / 2) + 0;
// 	data->r_z = 0;
// 	data->i_z = 0;
// 	data->temp = 0;
// 	data->it = 0;
// }

// void	ft_mandel_calc_z(t_data *data)
// {
// 	data->temp = pow(data->r_z, 2) - pow(data->i_z, 2) + data->r_c;
// 	data->i_z = (2 * data->r_z * data->i_z) + data->i_c;
// 	data->r_z = data->temp;
// 	data->it++;
// }

// void	ft_mandelbrot(t_data *data)
// {
// 	data->temp = 0;
// 	data->x = 0; //top left corner 
// 	data->y = 0; 

// 	while (data->x < data->win_height)
// 	{
// 		while (data->y < data->win_width)
// 		{
// 			ft_mandel_calc_c(data);
// 			while (data->it < 40 && (sqrt(pow(data->r_z, 2) + pow(data->i_z, 2)) <= 2))
// 			{
// 				ft_mandel_calc_z(data);
// 			}
// 			if (data->it < 40)
// 			{
// 				my_mlx_pixel_put(data, 0x00000000);
// 			}
// 			else
// 			{
// 				my_mlx_pixel_put(data, 0x00FFFFFF);
// 			}
// 			data->y++;
// 		}
// 		data->y = 0;
// 		data->x++;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
// }
*/