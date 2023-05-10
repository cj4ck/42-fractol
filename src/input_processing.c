/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:38:40 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 13:47:01 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Gate for fractal rendering initialization but
 * it works from the terminal and it's called after input check
 */
void	parse(t_env *e, char **av)
{
	e->color_palette = av[2][0];
	if (av[1][0] == '1')
		choose_fractal(KEY_1, e);
	else if (av[1][0] == '2')
		choose_fractal(KEY_2, e);
	else if (av[1][0] == '3')
		choose_fractal(KEY_3, e);
}

/**
 * @brief Reads instructions from a readme.txt file
 */
static void	print_instructions(void)
{
	int		fd;
	char	text[1500];
	int		readsize;

	fd = open("readme.txt", 0);
	readsize = read(fd, text, 1000);
	write(1, text, readsize);
	close(fd);
}

/**
 * @brief Checks if passed arguments are valid.
 */
void	input_check(t_env *e, int ac, char **av)
{
	if (ac != 3)
	{
		ft_error(e, "INVALID ARGUMENTS", 0);
		print_instructions();
		exit(EXIT_FAILURE);
	}
	else
	{
		if (av[1][1] || !ft_strchr("0123", (int)av[1][0]))
		{
			ft_error(e, "INVALID FRACTAL TYPE", -1);
			print_instructions();
		}
		if (av[2][1] || !ft_strchr("0123456789", (int)av[2][0]))
		{
			ft_error(e, "INVALID COLOR PALETTE", -1);
		}
	}
}
