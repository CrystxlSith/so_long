/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:37:58 by crystal           #+#    #+#             */
/*   Updated: 2024/07/13 00:50:09 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_img	ft_image(void *mlx, char *path, t_mlx_data *data)
{
	t_img	img;

	img.path = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	if (!img.path)
		ft_error(RED"Error\nfailed to create image\n"RESET, data);
	return (img);
}

static void	ft_init_images(t_mlx_data *data)
{
	data->ground = ft_image(data->mlx, "assets/grounds.xpm", data);
	data->wall = ft_image(data->mlx, "assets/walls.xpm", data);
	data->player = ft_image(data->mlx, "assets/elf.xpm", data);
	data->exit = ft_image(data->mlx, "assets/exit.xpm", data);
	data->collectible = ft_image(data->mlx, "assets/collectible.xpm", data);
}

void	ft_mlx_init(t_mlx_data *data)
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