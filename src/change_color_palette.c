/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color_palette.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:20 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 17:11:05 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Increse or decrese iteration.
*/
void	change_iter(t_env *e, int keycode)
{
	if (keycode == KEY_W)
	{
		if (e->iter < e->max_iter)
			e->iter += e->iterstep;
	}
	else
	{
		if (e->iter > e->min_iter)
			e->iter -= e->iterstep;
	}
	e->draw(e);
}

/**
 * @brief Color palette change options.
 */
void	change_color_palette(t_env *e)
{
	if (e->color_palette == '1')
	{
		e->color_palette = '2';
		set_color_palette(e);
	}
	else if (e->color_palette == '2')
	{
		e->color_palette = '3';
		set_color_palette(e);
	}
	else if (e->color_palette == '3')
	{
		e->color_palette = '4';
		set_color_palette(e);
	}
	else
		change_color_palette2(e);
	e->draw(e);
}

/**
 * @brief Color palette change options. More colors 🎉
 */
void	change_color_palette2(t_env *e)
{
	if (e->color_palette == '4')
	{
		e->color_palette = '5';
		set_color_palette(e);
	}
	else if (e->color_palette == '5')
	{
		e->color_palette = '6';
		set_color_palette(e);
	}
	else if (e->color_palette == '6')
	{
		e->color_palette = '7';
		set_color_palette(e);
	}
	else
		change_color_palette3(e);
	e->draw(e);
}

/**
 * @brief Color palette change options. Even more colors 🤩
 */
void	change_color_palette3(t_env *e)
{
	if (e->color_palette == '7')
	{
		e->color_palette = '8';
		set_color_palette(e);
	}
	else if (e->color_palette == '8')
	{
		e->color_palette = '9';
		set_color_palette(e);
	}
	else if (e->color_palette == '9')
	{
		e->color_palette = '1';
		set_color_palette(e);
	}
	e->draw(e);
}
