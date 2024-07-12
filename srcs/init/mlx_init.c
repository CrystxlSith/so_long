/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:37:58 by crystal           #+#    #+#             */
/*   Updated: 2024/07/12 23:35:22 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_init_images(t_mlx_data *data)
{

}

void	ft_mlx_init(t_mlx_data *data, int rows, int cols)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->mlx);
		ft_error("Error\nmlx_init failed\n", data);
	}
	data->win = mlx_new_window(data->mlx, data->rows * 32, data->cols * 32, "so_long");
	if (!data->win)
	{
		free(data->mlx);
		ft_error(RED"Error\nfailed to create new window\n"RESET, data);
	}
	ft_init_images(data);
	// mlx_key_hook(data->win, handle_input, &data);
	// print_image(data, "assets/AnyConv.com__grounds.xpm", 100, 100);
	// printf("Window created, count = %d\n", data->count);
	// mlx_loop(data->mlx);
	// printf("rows = %d, cols = %d\n", rows, cols);
}