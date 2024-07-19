/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:56:15 by crystal           #+#    #+#             */
/*   Updated: 2024/07/19 19:43:13 by crystal          ###   ########.fr       */
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
		ft_printf("%s\n", data->map_to_fill[i]);
		i++;
	}
	data->map_to_fill[i] = NULL;
}

static void	ft_fill(t_mlx_data *data, int y, int x, char c)
{
	if (y < 0 || x < 0 || y >= data->rows || x >= data->cols)
		return ;
	data->map_to_fill[y][x] = c;
	if (!strchr("1x", data->map_to_fill[y - 1][x]))
		ft_fill(data, y - 1, x, c);
	if (!strchr("1x", data->map_to_fill[y + 1][x]))
		ft_fill(data, y + 1, x, c);
	if (!strchr("1x", data->map_to_fill[y][x - 1]))
		ft_fill(data, y, x - 1, c);
	if (!strchr("1x", data->map_to_fill[y][x + 1]))
		ft_fill(data, y, x + 1, c);
}

void	verify_fill(t_mlx_data *data, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (!ft_strchr("CPE", data->map_to_fill[i][j]))
			{
				ft_printf("data : %c\n", data->map_to_fill[i][j]);
				ft_error(RED"Error\nMap is not surrounded by walls\n"RESET, data);
			}
			j++;
		}
		i++;
	}
}	

void	flood_fill(t_mlx_data *data)
{
	int	rows;
	int	cols;

	rows = data->rows;
	cols = data->cols;
	map_to_fill(data, rows + 1, cols + 1);
	ft_fill(data, data->pos.y, data->pos.x, 'x');
	verify_fill(data, cols, rows);
}