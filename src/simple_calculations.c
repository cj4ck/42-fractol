/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_general.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:14:15 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 16:45:08 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Simple range calculation
 */
void	calc_xyranges(t_env *e)
{
	e->x_range = e->x_max - e->x_min;
	e->y_range = e->y_max - e->y_min;
}

/**
 * @brief Simple absolute number calculation
 * @return (double) absolute num
 */
double	double_absolute(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/**
 * @brief Simple absolute number calculation
 * @return (int) absolute num
 */
int	int_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
