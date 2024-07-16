/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:59:00 by crystal           #+#    #+#             */
/*   Updated: 2024/07/16 15:58:25 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	make_mouv(t_mlx_data *data)
{
	render_map(data);
	return (0);
}

void	render_map(t_mlx_data *data)
{
	int	rows;
	int	cols;
	int	*pix;
	int bits_per_pixel;
	int size_line;
	int endian;
	int	pixel;

    pix = (int *)mlx_get_data_addr(data->mlx, &bits_per_pixel, &size_line, &endian);
	cols = 0;
	while (cols < data->cols)
	{
		rows = 0;
		while (rows < data->rows)
		{
			// if (cols % 2 == 0 && rows % 2 == 0)
				mlx_put_image_to_window(data->mlx, data->win, data->img.ground2, rows * 32, cols * 32);
			// if (cols % 2 != 0 && rows % 2 != 0)
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.ground1, rows * 32, cols * 32);
			if (data->map[cols][rows] == WALL)
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, rows * 32, cols * 32);
			else if (data->map[cols][rows] == EXIT)
				mlx_put_image_to_window(data->mlx, data->win, data->img.exit_closed, rows * 32, cols * 32);
			else if (data->map[cols][rows] == COLLECTIBLE)
				mlx_put_image_to_window(data->mlx, data->win, data->img.chest_closed, rows * 32, cols * 32);
			else if (data->map[cols][rows] == PLAYER)
				mlx_put_image_to_window(data->mlx, data->win, data->img.player_front, rows * 32, cols * 32);
			pixel = pix[cols * 32 + rows];
			if (pixel == TRANSPARENT_COLOR)
				pix[cols * 32 + rows] = BACKGROUND_COLOR;
			rows++;
		}
		cols++;
	}
}