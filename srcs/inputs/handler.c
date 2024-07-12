/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:19:52 by crystal           #+#    #+#             */
/*   Updated: 2024/07/13 00:52:13 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_input(int keycode, t_mlx_data *data)
{
	if (keycode == XK_Escape)
	{
		printf("Exiting...\n");
		free_all(data);
		exit(1);
	}
	// printf("Movements: %d\n", keycode);
	if (keycode == XK_Right || keycode == XK_Up || keycode == XK_Left || keycode == XK_Down)
	{
		//move_player(keycode, data);
		ft_printf("Movements : %d\n", data->movements += 1);
	}
	return (0);
}