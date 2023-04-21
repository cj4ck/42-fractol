/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:54:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/21 14:59:43 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

void	my_mlx_pixel_put(t_data *data, int color)
{
	char	*dst;

	dst = data->img_addr + ((int)data->y * data->line_length + (int)data->x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    ft_image_processing(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr,data->win_width, data->win_height);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length,
								&data->endian);
}

void	ft_mandel_calc_c(t_data *data)
{
	data->r_c = ((data->x / data->win_height) * 4) - (4 / 2) - 1;
	data->i_c = ((-1) * (data->y / data->win_width) * 4) + (4 / 2) + 0;
	data->r_z = 0;
	data->i_z = 0;
	data->temp = 0;
	data->it = 0;
}

void	ft_mandel_calc_z(t_data *data)
{
	data->temp = pow(data->r_z, 2) - pow(data->i_z, 2) + data->r_c;
	data->i_z = (2 * data->r_z * data->i_z) + data->i_c;
	data->r_z = data->temp;
	data->it++;
}

void	ft_mandelbrot(t_data *data)
{
	data->temp = 0;
	data->x = 0; //top left corner 
	data->y = 0; 

	while (data->x < data->win_height)
	{
		while (data->y < data->win_width)
		{
			ft_mandel_calc_c(data);
			while (data->it < 20 && (sqrt(pow(data->r_z, 2) + pow(data->i_z, 2)) <= 2))
			{
				ft_mandel_calc_z(data);
			}
			if (data->it < 20)
			{
				my_mlx_pixel_put(data, 0x00000000);
			}
			else
			{
				my_mlx_pixel_put(data, 0x00FFFFFF);
			}
			data->y++;
		}
		data->y = 0;
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}