/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:56:29 by crystal           #+#    #+#             */
/*   Updated: 2024/07/21 12:57:35 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_valid_content(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!is_valid_content(data->map[i][j], data->map_content))
				ft_error(RED"Something is wrong \
with your map!\n"RESET, data);
			if (data->map[i][j] == PLAYER)
			{
				data->map_content.player_found += 1;
				data->pos.x = j;
				data->pos.y = i;
			}
			if (data->map[i][j] == EXIT)
				data->map_content.exit_found += 1;
			if (data->map[i][j] == COLLECTIBLE)
				data->map_content.collectible_found += 1;
			j++;
		}
		i++;
	}
}

static void	check_walls(t_mlx_data *data)
{
	int	i;
	int	j;
	int	line_length;
	int	num_rows;

	i = 0;
	num_rows = 0;
	while (data->map[num_rows])
		num_rows++;
	while (data->map[i])
	{
		j = 0;
		line_length = ft_strlen(data->map[i]);
		while (data->map[i][j])
		{
			if ((i == 0 || i == num_rows - 1 || j == 0 || j == \
				line_length - 1) && data->map[i][j] != data->map_content.wall)
				ft_error(RED"Map is not surrounded by walls\n"RESET \
				, data);
			j++;
		}
		i++;
	}
}

static void	check_valid_map(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (data->count == 0)
		{
			data->rows = j;
			data->count = j;
		}
		if (data->count != j)
			ft_error(RED"Map is not rectangular\n"RESET, data);
		i++;
	}
	data->cols = i;
	check_valid_content(data);
}

void	check_map(t_mlx_data *data)
{
	check_valid_map(data);
	check_walls(data);
	if (data->rows < 3 || data->cols < 3)
		ft_error(RED"Map is too small\n"RESET, data);
	if (data->rows > 60 || data->cols > 32)
		ft_error(RED"Map is too big\n"RESET, data);
	if (data->map_content.player_found != 1 \
	|| data->map_content.exit_found != 1)
		ft_error(RED"There should be one \
player & exit\n"RESET, data);
	if (data->map_content.collectible_found < 1)
		ft_error(RED"There should be \
at least one collectible\n"RESET, data);
}
