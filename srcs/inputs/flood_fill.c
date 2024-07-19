/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:56:15 by crystal           #+#    #+#             */
/*   Updated: 2024/07/18 18:48:59 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	map_to_fill(t_mlx_data *data, int rows, int cols)
{
	int	i;

	i = 0;
	data->map_to_fill = ft_calloc(rows, sizeof(char *));
	if (!data->map_to_fill)
		ft_error(RED"Error\nCalloc failed {Fill}\n"RESET, data);
	while (i < cols)
	{
		data->map_to_fill[i] = ft_calloc(cols, sizeof(char));
		if (!data->map_to_fill[i])
			ft_error(RED"Error\nCalloc failed {Fill}\n"RESET, data);
		ft_strlcpy(data->map_to_fill[i], data->map[i], cols);
		i++;
	}
	data->map_to_fill[i] = NULL;
}

static void	ft_fill(t_mlx_data *data, int y, int x)
{
	
}

void	flood_fill(t_mlx_data *data)
{
	int	rows;
	int	cols;

	rows = data->rows;
	cols = data->cols;
	map_to_fill(data, rows, cols);
	ft_fill(data, data->pos.y, data->pos.x);
}