/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:57:22 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/21 11:49:18 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

// void	my_mlx_pixel_put(t_data *data, int color)
// {
// 	char	*dst;

// 	dst = data->img_addr + ((int)data->y * data->line_length + (int)data->x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void    ft_image_processing(t_data *data)
// {
// 	data->img_ptr = mlx_new_image(data->mlx_ptr,data->win_width, data->win_height);
// 	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length,
// 								&data->endian);
// }