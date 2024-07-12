/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:52:43 by crystal           #+#    #+#             */
/*   Updated: 2024/07/12 18:56:07 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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