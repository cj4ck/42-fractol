/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:04:24 by cjackows          #+#    #+#             */
/*   Updated: 2023/04/28 15:04:36 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!		---=[ init.c ]=---
/**
 * @brief  Initializes MLX and creates new window.
 *
 * @param ac Number of command line arguments
 * @param av Array of command line argument strings
 *
 * @return t_data* 	Returns a pointer to a initialized t_data struct.
 */
t_data	*ft_init(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	ft_parse(data, ac, av);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		printf("%sError: Failed to initialize new window%s\n", ERROR, NC);
		exit (EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, \
	data->win_height, data->win_title);
	if (data->win_ptr == NULL)
	{
		printf("%sError: Failed to initialize new window%s\n", ERROR, NC);
		exit (EXIT_FAILURE);
	}
	return (data);
}