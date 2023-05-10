/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:50:49 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 16:21:21 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Push info to MLX
 */
static void	ft_overlay_text(t_env *e)
{
	mlx_string_put(e->mlx, e->win, WIN_WIDTH - 360, 15, \
				e->hud_color, e->current_outside_set);
	mlx_string_put(e->mlx, e->win, WIN_WIDTH - 360, 25, \
				e->hud_color, e->current_inside_set);
	mlx_string_put(e->mlx, e->win, WIN_WIDTH - 241, 35, \
				e->hud_color, e->current_color_palette_str);
	mlx_string_put(e->mlx, e->win, WIN_WIDTH - 241, 45, \
				e->hud_color, e->current_iter_str);
}

/**
 * @brief Takes vars and creates right strings.
 */
void	ft_overlay(t_env *e)
{
	char	*iterations;

	iterations = ft_itoa(e->iter);
	e->current_outside_set = ft_strjoin("Pixels in outside set colored | ", \
e->outside_set_str);
	e->current_inside_set = ft_strjoin("Pixels in inside set colored  | ", \
e->inside_set_str);
	e->current_color_palette_str = ft_strjoin("Base color   | ", \
e->color_palette_str);
	e->current_iter_str = ft_strjoin("Iterations   | ", \
iterations);
	free (iterations);
	ft_overlay_text(e);
	free (e->current_outside_set);
	free (e->current_inside_set);
	free (e->current_color_palette_str);
	free (e->current_iter_str);
}
