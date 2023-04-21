/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:02:48 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/20 17:50:25 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/inc/libft.h"
# include "./minilibx_mms_20191025_beta/mlx.h"
// # include "./keymacros.h"
# include <math.h>

//	---= ft_printf Macros =---
# define ERROR "\033[0;31m!ERROR | "
# define GREEN "\033[1;32m"
# define NC "\033[0m"

// ---= structs =---
typedef struct s_fract {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_ptr2;
	void			*win_ptr2;

	double		r_c;
	double		i_c;
	double		i_z;
	double		r_z;
	double		x;
	double		y;
	
	double		temp;
	double		it;

	void			*img_ptr;
	char			*img_addr;
	int		bits_per_pixel;
	int		line_length;

	int		endian;
}	t_fract;

//	---= main.c =---

#endif
