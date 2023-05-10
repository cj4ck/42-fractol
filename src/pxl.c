/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:14:24 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 17:12:48 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Draws pixels by iterating through img_height and img_width.
 */
void	draw_pxl(t_env *e)
{
	int		x;
	int		y;

	calc_xyranges(e);
	y = 0;
	while (y < e->img_height)
	{
		x = 0;
		while (x < e->img_width)
		{
			map_pxl(e, x, y);
			put_pixel(e, x, y, e->fractal(e));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_overlay(e);
}

/**
 * @brief Maps pixels based on img x&y coordinates,
 * ranges must be correct, call calc_xyranges before.
 *  e->img_addr is a pointer to the start of the image buffer,
 * and (y * e->img_line_length + x * (e->img_bytespp)) calculates 
 * the offset to the pixel location based on its x and y coordinates. 
 * e->img_line_length is the number of bytes per row in the image buffer, 
 * and e->img_bytespp is the number of bytes per pixel.
 */
void	map_pxl(t_env *e, int x, int y)
{
	e->x_mappd = e->x_min + x * e->x_range / e->img_width;
	e->y_mappd = e->y_min + y * e->y_range / e->img_height;
}

/**
 * @brief Set the color of a pixel in an img buff at right img x&y coordinates,
 * with right color value. Pixel colors are stored as 4-byte (32-bit).
 */
void	put_pixel(t_env *e, int x, int y, int color)
{
	char	*pxl;

	pxl = e->img_addr + (y * e->img_line_length + x * (e->img_bytespp));
	*(unsigned int *)pxl = color;
}
