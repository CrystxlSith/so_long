/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:19:42 by crystal           #+#    #+#             */
/*   Updated: 2024/07/17 18:12:20 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_map_content(t_mlx_data *data)
{
	data->map_allocated = false;
	data->count = 0;
	data->map_content.wall = '1';
	data->map_content.exit = 'E';
	data->map_content.collectible = 'C';
	data->map_content.player = 'P';
	data->map_content.ground = '0';
}
