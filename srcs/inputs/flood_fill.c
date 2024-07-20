/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:56:15 by crystal           #+#    #+#             */
/*   Updated: 2024/07/20 21:48:56 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	map_to_fill(t_mlx_data *data, int cols, int rows)
{
	int	i;

	i = 0;
	data->map_to_fill = ft_calloc(rows, sizeof(char *));
	if (!data->map_to_fill)
		ft_error(RED"Error\nCalloc failed {Fill}\n"RESET, data);
	while (i < rows - 1)
	{
		data->map_to_fill[i] = ft_calloc(cols, sizeof(char));
		if (!data->map_to_fill[i])
			ft_error(RED"Error\nCalloc failed {Fill}\n"RESET, data);
		ft_strlcpy(data->map_to_fill[i], data->map[i], cols);
		i++;
	}
	data->map_to_fill[i] = NULL;
}

static void	ft_fill(t_mlx_data *data, int y, int x, char c)
{
	if (y < 0 || x < 0 || x >= data->rows || y >= data->cols)
		return ;
	data->map_to_fill[y][x] = c;
	if (!ft_strchr("1X", data->map_to_fill[y][x - 1]))
		ft_fill(data, y, x - 1, c);
	if (!ft_strchr("1X", data->map_to_fill[y - 1][x]))
		ft_fill(data, y - 1, x, c);
	if (!ft_strchr("1X", data->map_to_fill[y][x + 1]))
		ft_fill(data, y, x + 1, c);
	if (!ft_strchr("1X", data->map_to_fill[y + 1][x]))
		ft_fill(data, y + 1, x, c);
}

void	verify_fill(t_mlx_data *data, int cols, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (ft_strchr("CPE", data->map_to_fill[i][j]))
			{
				ft_printf(RED"You need to reach this \
: %c\n"RESET, data->map_to_fill[i][j]);
				ft_error(RED"You can't finish this map ! "RESET, data);
			}
			j++;
		}
		i++;
	}
	free_map(data->map_to_fill);
}

void	flood_fill(t_mlx_data *data)
{
	int	rows;
	int	cols;

	rows = data->rows;
	cols = data->cols;
	map_to_fill(data, rows + 1, cols + 1);
	ft_fill(data, data->pos.y, data->pos.x, 'X');
	verify_fill(data, rows, cols);
}
