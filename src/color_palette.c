/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:57:20 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 16:17:04 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Set the color palette max colors as default
 */
void	set_color_palette_default(t_env *e)
{
	e->maxcolor_r = 255;
	e->maxcolor_g = 255;
	e->maxcolor_b = 255;
}

/**
 * @brief Set the color palette, manipulates mincolor values to do so.
 */
void	set_color_palette(t_env *e)
{
	set_color_palette_default(e);
	if (e->color_palette == '1')
	{
		e->color_palette_str = "Light Red";
		e->mincolor_r = 200;
		e->mincolor_g = 50;
		e->mincolor_b = 20;
	}
	else if (e->color_palette == '2')
	{
		e->color_palette_str = "Light Green";
		e->mincolor_r = 50;
		e->mincolor_g = 200;
		e->mincolor_b = 20;
	}
	if (e->color_palette == '3')
	{
		e->color_palette_str = "Light Blue";
		e->mincolor_r = 0;
		e->mincolor_g = 100;
		e->mincolor_b = 200;
	}
	else
		set_color_palette2(e);
}

/**
 * @brief More color palette options! 🎉
 */
void	set_color_palette2(t_env *e)
{
	if (e->color_palette == '4')
	{
		e->color_palette_str = "Bloody Red";
		e->mincolor_r = 136;
		e->mincolor_g = 8;
		e->mincolor_b = 8;
	}
	if (e->color_palette == '5')
	{
		e->color_palette_str = "Leafy Green";
		e->mincolor_r = 5;
		e->mincolor_g = 80;
		e->mincolor_b = 30;
	}
	if (e->color_palette == '6')
	{
		e->color_palette_str = "Thunder Blue";
		e->mincolor_r = 5;
		e->mincolor_g = 50;
		e->mincolor_b = 80;
	}
	else
		set_color_palette3(e);
}

/**
 * @brief Even more color palette oprions! 🤩
 */
void	set_color_palette3(t_env *e)
{
	if (e->color_palette == '7')
	{
		e->color_palette_str = "Snow";
		e->mincolor_r = 255;
		e->mincolor_g = 255;
		e->mincolor_b = 255;
	}
	else if (e->color_palette == '8')
	{
		e->color_palette_str = "Cold Void";
		e->maxcolor_r = 0;
		e->maxcolor_g = 0;
		e->maxcolor_b = 0;
		e->mincolor_r = 0;
		e->mincolor_g = 0;
		e->mincolor_b = 0;
	}
	else if (e->color_palette == '9')
	{
		e->color_palette_str = "Graphite";
		e->mincolor_r = 20;
		e->mincolor_g = 20;
		e->mincolor_b = 20;
	}
}
