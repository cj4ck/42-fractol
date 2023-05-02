/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:12:27 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/02 09:22:17 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

//!		---=[ magic.c ]=---
// /**
//  * @brief Renders a PNG image and do an operation on it, 
//  * displaying the result on a window.
//  *?	[ ] Later on we can generate fractal from images.
//  * @param data The data struct containing the mlx_ptr, win_ptr, 
//  * and other image-related variables.
//  * @return void
//  */
// void	ft_test(t_data *data)
// {
// 	int width;
// 	int	height;
// 	data->img_ptr = mlx_new_image(data->mlx_ptr, 1920, 1920);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
// 	data->img_ptr = mlx_png_file_to_image(data->mlx_ptr, "./png.png", &width, &height);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
// 	width /= 2;
//     height /= 2;
// 	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_size, &data->endian);
// 	void *scaled_img_ptr = mlx_new_image(data->mlx_ptr, width, height);
// 	char *scaled_img_data = mlx_get_data_addr(scaled_img_ptr, &data->bpp, &data->line_size, &data->endian);
// 	int y = 0;
// 	while (y < height) {
// 		int x = 0;
// 		while (x < width) {
// 			int src_x = x * 2;
// 			int src_y = y * 2;
// 			int dst_index = (y * data->line_size) + (x * data->bpp / 8);
// 			int src_index = (src_y * data->line_size * 2) + (src_x * data->bpp / 8);
// 			int i = 0;
// 			while (i < data->bpp / 8) {
// 				scaled_img_data[dst_index + i] = data->img_data[src_index + i];
// 				i++;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, scaled_img_ptr, 0, 0);
// }