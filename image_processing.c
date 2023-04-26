/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:57:22 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/24 14:21:50 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"
//!     ---=[ image_processing.c ]=---
/*
void			*mlx_new_image(void *mlx_ptr,int width,int height);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
*/

/**
 * @brief Function for creating a buffer of a main image
 * 
 * @param buffer 
 * @param data 
 */
void *ft_image_buffer_init(unsigned char **buffer, t_data *data)
{
	*buffer = malloc(data->win_width * data->win_height * sizeof(unsigned char) * 4); // 4 bytes per pixel (RGBA)
	if (*buffer == NULL) 
    {
		printf("%sError: Failed to allocate memory for main image buffer%s\n", ERROR, NC);
		exit (EXIT_FAILURE);
    }
	return	buffer;
}

void	my_mlx_pixel_put(t_data *data, int color)
{
	char	*dst;

	dst = data->img_data + ((int)data->y * data->line_size + (int)data->x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

/**
 * @brief 
 * 
 * @param data  
 */
void	ft_image_init(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr,data->win_width, data->win_height);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_size, &data->endian);
	if (data->img_data == NULL)
    {
		printf("%sError: Failed to initialize new image%s\n", ERROR, NC);
		exit (EXIT_FAILURE);
    }
}