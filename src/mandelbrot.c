/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:25:37 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 18:26:47 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Set the vars for mandelbrot
*/
void	set_vars_brot(t_env *e)
{
	e->x_min = -2.7;
	e->x_max = e->x_min * -0.6;
	e->x_range = e->x_max - e->x_min;
	e->iter = 100;
}
