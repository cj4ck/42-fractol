/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:29 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 17:10:27 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Modify vars based on arrow movement
 */
void	move_key(t_env *e, int key)
{
	double		movestep;

	calc_xyranges(e);
	movestep = e->y_range * e->movefactor;
	if (key == KEY_LEFT)
	{
		e->x_max -= movestep;
		e->x_min -= movestep;
	}
	if (key == KEY_RIGHT)
	{
		e->x_min += movestep;
		e->x_max += movestep;
	}
	if (key == KEY_UP)
	{
		e->y_min -= movestep;
		e->y_max -= movestep;
	}
	if (key == KEY_DOWN)
	{
		e->y_min += movestep;
		e->y_max += movestep;
	}
	e->draw(e);
}

/**
 * @brief Change env vars based on zoomfactor
 */
void	zoom(t_env *e, int zoom_in)
{
	if (zoom_in)
	{
		e->x_min += (e->x_mappd - e->x_min) * 0.2;
		e->x_max -= (e->x_max - e->x_mappd) * 0.2;
		e->y_min += (e->y_mappd - e->y_min) * 0.2;
		e->y_max -= (e->y_max - e->y_mappd) * 0.2;
		e->i++;
	}
	else
	{
		e->x_min -= (e->x_mappd - e->x_min) * 0.2;
		e->x_max += (e->x_max - e->x_mappd) * 0.2;
		e->y_min -= (e->y_mappd - e->y_min) * 0.2;
		e->y_max += (e->y_max - e->y_mappd) * 0.2;
		e->i--;
	}
	if (e->i >= 5)
	{
		if (e->iter < e->max_iter)
			e->iter += e->iterstep;
		e->i = 0;
	}
	e->r_min = 2 * e->y_range / e->img_height;
	e->line = 2 * e->y_range / e->img_height;
	e->draw(e);
}
