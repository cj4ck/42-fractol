/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:00:49 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 17:11:13 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Change inside set colorized used.
 */
void	change_inside_set(t_env *e)
{
	if (e->inside_set == black)
	{
		e->inside_set_str = "white";
		e->inside_set = white;
	}
	else if (e->inside_set == white)
	{
		e->inside_set_str = "web";
		e->inside_set = web;
	}
	else if (e->inside_set == web)
	{
		e->inside_set_str = "glitched";
		e->inside_set = glitched;
	}
	else if (e->inside_set == glitched)
	{
		e->inside_set_str = "black";
		e->inside_set = black;
	}
	e->draw(e);
}

/**
 * @brief Change outside set colorized used.
*/
void	change_outside_set(t_env *e)
{
	if (e->outside_set == solid)
	{
		e->outside_set = candy;
		e->outside_set_str = "candy land";
		e->hud_color = 0;
	}
	else if (e->outside_set == candy)
	{
		e->outside_set = doppler;
		e->outside_set_str = "doppler effect";
		e->hud_color = 0x00FFFFFF;
	}
	else
		change_outside_set2(e);
	e->draw(e);
}

/**
 * @brief More outside sets colorizers 🎉
*/
void	change_outside_set2(t_env *e)
{
	if (e->outside_set == doppler)
	{
		e->outside_set = bernstein;
		e->outside_set_str = "bernstein";
		e->hud_color = 0xFFFFFFFF;
	}
	else if (e->outside_set == bernstein)
	{
		e->outside_set = rev_bernstein;
		e->outside_set_str = "reverse bernstein";
	}
	else if (e->outside_set == rev_bernstein)
	{
		e->outside_set = solid;
		e->outside_set_str = "solid";
	}
	e->draw(e);
}
