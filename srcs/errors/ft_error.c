/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:32:57 by crystal           #+#    #+#             */
/*   Updated: 2024/07/13 19:30:21 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_mlx_free_images(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img.chest_open);
	mlx_destroy_image(data->mlx, data->img.chest_closed);
	mlx_destroy_image(data->mlx, data->img.exit_open);
	mlx_destroy_image(data->mlx, data->img.exit_closed);
	mlx_destroy_image(data->mlx, data->img.ground1);
	mlx_destroy_image(data->mlx, data->img.ground2);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.player_back);
	mlx_destroy_image(data->mlx, data->img.player_front);
	mlx_destroy_image(data->mlx, data->img.player_left);
	mlx_destroy_image(data->mlx, data->img.player_right);
}

void	free_all(t_mlx_data *data)
{
	ft_mlx_free_images(data);
	if (data->map_allocated == true)
		free_map(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
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
void	ft_close_all(t_mlx_data *data)
{
	printf("Exiting...\n");
	free_all(data);
	exit(1);
}