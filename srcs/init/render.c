/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:59:00 by crystal           #+#    #+#             */
/*   Updated: 2024/07/17 18:20:33 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	put_image_to_window(t_mlx_data *data, void *path, \
int rows, int cols)
{
	mlx_put_image_to_window(data->mlx, data->win, path, rows * 32, cols * 32);
}

int	make_mouv(t_mlx_data *data)
{
	render_map(data);
	return (0);
}

void	render_map(t_mlx_data *data)
{
	int	rows;
	int	cols;

	cols = 0;
	while (cols < data->cols)
	{
		rows = 0;
		while (rows < data->rows)
		{
			put_image_to_window(data, data->img.ground2, rows, cols);
			if (data->map[cols][rows] == WALL)
				put_image_to_window(data, data->img.wall, rows, cols);
			else if (data->map[cols][rows] == EXIT)
				put_image_to_window(data, data->img.exit_closed, rows, cols);
			else if (data->map[cols][rows] == COLLECTIBLE)
				put_image_to_window(data, data->img.chest_closed, rows, cols);
			else if (data->map[cols][rows] == PLAYER)
				put_image_to_window(data, data->img.player_front, rows, cols);
			rows++;
		}
		cols++;
	}
}
