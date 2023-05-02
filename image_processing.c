/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:57:22 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/02 08:51:20 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"
//!     ---=[ image_processing.c ]=---
//? void			*mlx_new_image(void *mlx_ptr,int width,int height);
//? char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
//? int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
//? unsigned int	mlx_get_color_value(void *mlx_ptr, int color);


/**
 * @brief	Initializes a new image for the given MLX data.
 *
 * @param data Pointer to the program data struct.
 */
void	ft_image_init(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->win_width, \
	data->win_height);
	if (data->img_ptr == NULL)
	{
		printf("%sFailed to initialize new image%s\n", ERROR, NC);
		exit(EXIT_FAILURE);
	}
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp, \
	&data->line_size, &data->endian);
}

/**
 * @brief Function for creating a main image buffer.
 *  Used as a temporary storage space for image manipulation 
 * 	operations such as scaling, rotation, and compositing. 
 * 	Once the image processing is complete, the buffer can be written 
 * 	back to a file or displayed on the screen.
 *
 * @param buffer Pointer to the main image buffer.
 * 	(*4 bytes per pixel (RGBA))
 * @param data Pointer to the program data struct.
 */
unsigned char	**ft_image_buffer_init(unsigned char **buffer, t_data *data)
{
	*buffer = malloc(data->win_width * data->win_height * \
	sizeof(unsigned char) * 4);
	if (*buffer == NULL)
	{
		printf("%sFailed to allocate memory for \
		main image buffer%s\n", ERROR, NC);
		exit(EXIT_FAILURE);
	}
	return (buffer);
}

void	my_mlx_pixel_put(t_data *data, int color)
{
	char	*dst;

	dst = data->img_data + ((int)data->y * data->line_size + \
	(int)data->x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
