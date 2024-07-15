/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:59:00 by crystal           #+#    #+#             */
/*   Updated: 2024/07/15 08:02:50 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
			if (cols % 2 == 0 && rows % 2 == 0)
				mlx_put_image_to_window(data->mlx, data->win, data->img.ground1, rows * 32, cols * 32);
			else
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, rows * 32, cols * 32);
			if (data->map[cols][rows] == WALL)
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, rows * 32, cols * 32);
			else if (data->map[cols][rows] == EXIT)
				mlx_put_image_to_window(data->mlx, data->win, data->img.exit_closed, rows * 32, cols * 32);
			else if (data->map[cols][rows] == COLLECTIBLE)
				mlx_put_image_to_window(data->mlx, data->win, data->img.chest_closed, rows * 32, cols * 32);
			else if (data->map[cols][rows] == PLAYER)
				mlx_put_image_to_window(data->mlx, data->win, data->img.player_front, rows * 32, cols * 32);
			rows++;
		}
		cols++;
	}
}