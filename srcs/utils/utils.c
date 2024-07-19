/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:52:43 by crystal           #+#    #+#             */
/*   Updated: 2024/07/18 17:52:09 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	new_player(t_mlx_data *data, char *path)
{
	mlx_destroy_image(data->mlx, data->img.player_front);
	data->img.player_front = mlx_xpm_file_to_image(data->mlx, path, \
&data->img.x, &data->img.y);
}

void	new_exit(t_mlx_data *data)
{
	if (data->map_content.collectible_found == 0)
	{
		mlx_destroy_image(data->mlx, data->img.exit_closed);
		data->img.exit_closed = mlx_xpm_file_to_image(data->mlx, \
EXIT_OP_PATH, &data->img.x, &data->img.y);
	}
}

int	is_valid_content(char c, t_map_content map_content)
{
	if (c != map_content.wall
		&& c != map_content.exit
		&& c != map_content.collectible
		&& c != map_content.player
		&& c != map_content.ground)
		return (0);
	return (1);
}
