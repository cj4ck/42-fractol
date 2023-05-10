/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:38:40 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/10 18:36:48 by cjackows         ###   ########.fr       */
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
	else if (av[1][0] == '4')
		choose_fractal(KEY_4, e);
	else if (av[1][0] == '5')
		choose_fractal(KEY_5, e);
	else if (av[1][0] == '6')
		choose_fractal(KEY_6, e);
	else if (av[1][0] == '7')
		choose_fractal(KEY_7, e);
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
		if (av[1][1] || !ft_strchr("01234567", (int)av[1][0]))
		{
			ft_error(e, "INVALID FRACTAL TYPE", -1);
			print_instructions();
		}
		if (av[2][1] || !ft_strchr("123456789", (int)av[2][0]))
		{
			ft_error(e, "INVALID COLOR PALETTE", -1);
		}
	}
}

/**
 * @brief Function for printing error and exiting the program. Basicly on
 * failure it displays error_msg for example place where it failed. 
 * It's very usefull to debug things and still exit without memory leaks.
 */
void	ft_error(t_env *e, char	*error_msg, int failure)
{
	ft_printf("%s%s%s\n", ERROR, error_msg, NC);
	if (failure)
		my_exit(e, failure);
}
