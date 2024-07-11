/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:19:52 by crystal           #+#    #+#             */
/*   Updated: 2024/07/11 17:56:42 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_input(int keycode, t_mlx_data *data)
{
	if (keycode == XK_Escape)
	{
		printf("Exiting...\n");
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	printf("Keycode: %d\n", keycode);
	return (0);
}