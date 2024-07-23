/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:37:58 by crystal           #+#    #+#             */
/*   Updated: 2024/07/22 14:22:59 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_mlx_init(t_mlx_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->mlx);
		ft_error("mlx_init failed\n", data);
	}
	data->win = mlx_new_window(data->mlx, data->rows * 32, \
	data->cols * 32, "so_long");
	if (!data->win)
	{
		free(data->mlx);
		ft_error(RED"failed to create new window\n"RESET, data);
	}
}
