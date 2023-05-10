/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_calculations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:14:34 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 16:31:21 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Computes the Mandelbrot set for a given point in the complex plane.
 *       n = iterations taken before determining that a point is outside the set
 *	  x, y = current pos of the point being tested in the complex plane.
 * 	temp_y = stores temp y during the calc of the next x and y values.
 * 	This is because the value of y needs to be updated based on the original 
 *	value of x, not the updated value of x. Storing the original value of y in 
 * 	temp_y ensures that the correct value of y is used in the calculation of the 
 * 	updated x and y values.
 * @return The color value for the computed point
 */
int	mandelbrot(t_env *e)
{
	int		n;
	double	x;
	double	y;
	double	temp_y;

	n = 0;
	x = 0;
	y = 0;
	while (n < e->iter)
	{
		if (x * x + y * y > 4)
			return (e->outside_set(e, n));
		temp_y = 2 * x * y + e->y_mappd;
		x = x * x - y * y + e->x_mappd;
		y = temp_y;
		n++;
	}
	return (e->inside_set((int)(x * 10000), (int)(y * 10000)));
}

/**
 * @brief Computes the Julia set for a given point in the complex plane.
 * @return The color value for the computed point
 */
int	julia(t_env *e)
{
	int		n;
	double	x;
	double	y;
	double	temp_y;

	n = 0;
	x = e->x_mappd;
	y = e->y_mappd;
	while (n < e->iter)
	{
		if (x * x + y * y > 4)
			return (e->outside_set(e, n));
		temp_y = 2 * x * y + e->julia_y;
		x = x * x - y * y + e->julia_x;
		y = temp_y;
		n++;
	}
	return (e->inside_set((int)(x * 10000), (int)(y * 10000)));
}

/**
 * @brief Computes the Burning Ship set for a given point in the complex plane.
 * @return The color value for the computed point
 */
int	burningship(t_env *e)
{
	int		n;
	double	x;
	double	y;
	double	temp_y;

	n = 0;
	x = 0;
	y = 0;
	while (n < e->iter)
	{
		if (x * x + y * y > 4)
			return (e->outside_set(e, n));
		temp_y = double_absolute(2 * x * y) + e->y_mappd;
		x = x * x - y * y + e->x_mappd;
		y = temp_y;
		n++;
	}
	return (e->inside_set((int)(x * 10000), (int)(y * 10000)));
}
