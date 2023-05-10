/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:46 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 16:36:59 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Returns black color
 */
int	black(__attribute__((unused)) int x, __attribute__((unused)) int y)
{
	return (0);
}

/**
 * @brief Returns white color
 */
int	white(__attribute__((unused)) int x, __attribute__((unused)) int y)
{
	return (0x00FFFFFF);
}

/**
 * @brief Returnes black or white based on coordinates.
 */
int	web(int x, int y)
{
	if (y == 0 || x == 0)
		return (0x00000000);
	if (y % 8 == 0 || x % 8 == 0)
		return (0x00000000);
	return (0x00FFFFFF);
}

/**
 * @brief Returns old TV pixels screen effect.
*/
int	glitched(int x, int y)
{
	if (y == 0 || x == 0)
		return (0x00000000);
	if (y % 9 == 0 || x % 9 == 0)
		return (0x0000FF00);
	if (y % 6 == 0 || x % 6 == 0)
		return (0x00FF0000);
	if (y % 3 == 0 || x % 3 == 0)
		return (0x000000FF);
	return (0x00000000);
}
