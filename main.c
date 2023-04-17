/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:13 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

// /*
// 	Used for user input
// */
// static void	input_check (int ac, char **av)
// {
// 	int	error;

// 	error = 0;
// 	if (ac == 3)
// 	{
// 		if (ft_atoi(av[1]) < 800 || ft_atoi(av[1]) > 1920)
// 			error = 1;
// 		if ((ft_strncmp("Mandelbrot", av[2], 11) * \
// 		ft_strncmp("Julia", av[2], 5)) != 0)
// 			error = 1;
// 	}
// 	else
// 		error = 1;
// 	if (error == 1)
// 	{
// 		ft_printf("%sInvalid arguments \n	---= Program takes: =---\n\
// 	[1] - window resolution ( x =< 1920 & x >= 800)\n\
// 	[2] - type of fractol   ( \"Mandelbrot\" or \"Julia\")%s\n", ERROR, NC);
// 		exit (error);
// 	}
// }

// int	main(int ac, char *av[])
// {
// 	void	*mlx_init();
// 	return (0);
// }

// #include "./includes/minilibx_mms_20191025_beta/mlx.h"

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Create Image");
    
    // The following code goes here.

    mlx_loop(mlx);
}