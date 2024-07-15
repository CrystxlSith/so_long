/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:19:52 by crystal           #+#    #+#             */
/*   Updated: 2024/07/13 14:50:41 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_input(int keycode, t_mlx_data *data)
{
	if (keycode == XK_Escape)
		ft_close_all(data);
	// printf("Movements: %d\n", keycode);s
	if (keycode == XK_z || keycode == XK_q || keycode == XK_s || keycode == XK_d)
	{
		//move_player(keycode, data);
		ft_printf("Movements : %d\n", data->movements += 1);
	}
	return (0);
}