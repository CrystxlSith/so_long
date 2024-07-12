/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:32:57 by crystal           #+#    #+#             */
/*   Updated: 2024/07/12 22:55:14 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_mlx_free_images(t_mlx_data *data)
{
	if (data->img.)
		mlx_destroy_image(data->mlx, data->img);
	if (data->img2)
		mlx_destroy_image(data->mlx, data->img2);
	if (data->img3)
		mlx_destroy_image(data->mlx, data->img3);
	if (data->img4)
		mlx_destroy_image(data->mlx, data->img4);
	if (data->img5)
		mlx_destroy_image(data->mlx, data->img5);
}

void	free_all(t_mlx_data *data)
{
	if (data->map_allocated == true)
		free_map(data->map);
	free(data->mlx);
	ft_mlx_destroy_images(data);
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