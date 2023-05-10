/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:34 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 17:11:18 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Keyboard input handling function, gate for keyboard events.
 */
int	keyboard(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		my_exit(e, 0);
	if (keycode == KEY_LEFT || keycode == KEY_UP || \
keycode == KEY_RIGHT || keycode == KEY_DOWN)
		move_key(e, keycode);
	if (keycode == KEY_W || keycode == KEY_S)
		change_iter(e, keycode);
	if (keycode == KEY_I)
		change_inside_set(e);
	if (keycode == KEY_O)
		change_outside_set(e);
	if (keycode == KEY_C)
		change_color_palette(e);
	if (keycode == KEY_H)
		julia_shape(e, KEY_H);
	if (keycode == KEY_J)
		julia_shape(e, KEY_J);
	if (keycode == KEY_K)
		julia_shape(e, KEY_K);
	if (keycode == KEY_L)
		julia_shape(e, KEY_L);
	if (keycode == KEY_R)
		reset_values(e);
	return (0);
}

/**
 * @brief Mouse input handling, gate for mouse events.
 */
int	mouse_press(int button, int mouse_x, int mouse_y, t_env *e)
{
	map_pxl(e, mouse_x, mouse_y);
	if (button == MOUSE_LEFT)
	{
		e->mouse_press_x = mouse_x;
		e->mouse_press_y = mouse_y;
	}
	if (button == MOUSE_SCR_UP)
		zoom(e, 1);
	if (button == MOUSE_SCR_DOWN)
		zoom(e, 0);
	return (0);
}

/**
 * @brief Mouse input handling, gate for mouse events.
 */
int	mouse_release(int button, int mouse_x, int mouse_y, t_env *e)
{
	int		threshold;

	threshold = 35;
	map_pxl(e, mouse_x, mouse_y);
	if (button == MOUSE_RIGHT)
		zoom(e, 0);
	else
	{
		e->mouse_release_x = mouse_x;
		e->mouse_release_y = mouse_y;
		if (int_absolute(e->mouse_press_x - mouse_x) < threshold
			&& int_absolute(e->mouse_press_y - mouse_y) < threshold)
			zoom(e, 1);
	}
	return (0);
}

/**
 * @brief Change julia_shape in real time
*/
void	julia_shape(t_env *e, int keycode)
{
	if (keycode == KEY_H)
		e->julia_x += 0.1;
	if (keycode == KEY_J)
		e->julia_x -= 0.1;
	if (keycode == KEY_K)
		e->julia_y += 0.1;
	if (keycode == KEY_L)
		e->julia_y -= 0.1;
	e->draw(e);
}

/**
 * @brief Called after pressing reset button, resets the env vars
 */
void	reset_values(t_env *e)
{
	set_env(e);
	zoom(e, 0);
}
