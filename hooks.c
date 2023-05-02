/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:53:50 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/02 08:47:47 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

//!		---=[ hooks.c ]=---
/**
 * @brief 
 * 
 * @param keycode Every keyboard button, has a keycode
 * @param data Pointer to the MLX data struct.
 * @return int 
 */
int	ft_key_press_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
	{
		ft_exit(data, 0);
	}
	return (0);
}
