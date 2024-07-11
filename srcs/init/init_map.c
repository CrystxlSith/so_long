/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:19:42 by crystal           #+#    #+#             */
/*   Updated: 2024/07/11 17:25:30 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_map_content(t_map_content *content)
{
	content->wall = '1';
	content->exit = 'E';
	content->collectible = 'C';
	content->player = 'P';
	content->ground = '0';
}