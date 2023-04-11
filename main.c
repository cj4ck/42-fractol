/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/11 15:30:12 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void	input_error_check(int ac, char **av)
{
	int	error;

	error = 0;
	if (ac == 3)
	{
		if (ft_atoi(av[1]) < 800 || ft_atoi(av[1]) > 1920)
			error = 1;
		if ((ft_strncmp("Mandelbrot", av[2], 11) * \
		ft_strncmp("Julia", av[2], 5)) != 0)
			error = 1;
	}
	else
		error = 1;
	if (error == 1)
	{
		ft_printf("%sInvalid arguments \n	---= Program takes: =---\n\
	[1] - window resolution ( x =< 1920 & x >= 800)\n\
	[2] - type of fractol   ( \"Mandelbrot\" or \"Julia\")%s\n", ERROR, NC);
		exit (error);
	}
}

int	main(int ac, char *av[])
{
	//t_fract	*current_frame;

	input_error_check(ac, av);
	return (0);
}
