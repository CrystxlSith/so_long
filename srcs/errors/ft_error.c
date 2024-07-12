/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:32:57 by crystal           #+#    #+#             */
/*   Updated: 2024/07/13 00:05:29 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_mlx_free_images(t_mlx_data *data)
{
	if (data->ground.path)
		mlx_destroy_image(data->mlx, data->ground.path);
	if (data->wall.path)
		mlx_destroy_image(data->mlx, data->wall.path);
	if (data->player.path)
		mlx_destroy_image(data->mlx, data->player.path);
	if (data->exit.path)
		mlx_destroy_image(data->mlx, data->exit.path);
	if (data->collectible.path)
		mlx_destroy_image(data->mlx, data->collectible.path);
}

void	free_all(t_mlx_data *data)
{
	ft_mlx_free_images(data);
	if (data->map_allocated == true)
		free_map(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data)
		free(data);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**ft_error(char *str, t_mlx_data *data)
{
	ft_putstr_fd(str, 2);
	if (data->map_allocated == true)
		free_map(data->map);
	if (data)
		free(data);
	exit(1);
}