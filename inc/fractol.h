/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:02:48 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/17 16:10:42 by cjackows         ###   ########.fr       */
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

	void			*img;
	char			*img_addr;
}	t_fract;

//	---= main.c =---

#endif
