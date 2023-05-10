/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_set_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:58 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 15:44:53 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Solid colors
 */
int	solid(t_env *e, int n)
{
	int		r;
	int		g;
	int		b;

	r = (e->maxcolor_r - e->mincolor_r) * n / e->max_iter + e->mincolor_r;
	g = (e->maxcolor_g - e->mincolor_g) * n / e->max_iter + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * n / e->max_iter + e->mincolor_b;
	return (0x00 << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief Solid colors, but random overflow into t, mask is used.
*/
int	candy(t_env *e, int n)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	ratio = (double)n * e->max_iter;
	r = (e->maxcolor_r - e->mincolor_r) * ratio + e->mincolor_r;
	g = (e->maxcolor_g - e->mincolor_g) * ratio + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * ratio + e->mincolor_b;
	return (0x00FFFFFF & (0x00 << 24 | r << 16 | g << 8 | b));
}

/**
 * @brief Solid colors, but random overflow into t.
 */
int	doppler(t_env *e, int n)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	ratio = (double)n * e->max_iter;
	r = (e->maxcolor_r - e->mincolor_r) * ratio + e->mincolor_r;
	g = (e->maxcolor_g - e->mincolor_g) * ratio + e->mincolor_g;
	b = (e->maxcolor_b - e->mincolor_b) * ratio + e->mincolor_b;
	return (0x00 << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief Bernstein color formula.
 */
int	bernstein(t_env *e, int n)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	ratio = (double)n / e->max_iter;
	r = 9 * (1 - ratio) * ratio * ratio * ratio * 255;
	g = 15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255;
	b = 8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255;
	return (0x00 << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief Reversed Bernstein color formula.
 */
int	rev_bernstein(t_env *e, int n)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	ratio = (double)n / e->max_iter;
	b = 9 * (1 - ratio) * ratio * ratio * ratio * 255;
	g = 15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255;
	r = 8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255;
	return (0x00 << 24 | r << 16 | g << 8 | b);
}
