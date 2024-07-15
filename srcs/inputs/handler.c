/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:19:52 by crystal           #+#    #+#             */
/*   Updated: 2024/07/15 11:25:24 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_down(t_mlx_data *data)
{
	if (data->map[data->player_pos.y + 1][data->player_pos.x] != WALL)
	{
		if (data->map[data->player_pos.y + 1][data->player_pos.x] == COLLECTIBLE)
		{
			data->map[data->player_pos.y][data->player_pos.x] = GROUND;
			data->map_content.collectible_found -= 1;
		}
		else if (data->map[data->player_pos.y + 1][data->player_pos.x] == EXIT)
		{
			if (data->map_content.collectible_found == 0)
				exit(1); /*AJOUTER ECRAN DE WIN ET FREE TOUT CE QUI A ETE ALLOUE*/
		}
		else if (data->map[data->player_pos.y + 1][data->player_pos.x] == GROUND)
		{
			data->map[data->player_pos.y][data->player_pos.x] = GROUND;
		}
		data->map[data->player_pos.y + 1][data->player_pos.x] = PLAYER;
		data->player_pos.y += 1;
	}
}

static void	move_left(t_mlx_data *data)
{
	if (data->map[data->player_pos.y][data->player_pos.x - 1] != WALL)
	{
		if (data->map[data->player_pos.y][data->player_pos.x - 1] == COLLECTIBLE)
		{
			data->map[data->player_pos.y][data->player_pos.x] = GROUND;
			data->map_content.collectible_found -= 1;
		}
		else if (data->map[data->player_pos.y][data->player_pos.x - 1] == EXIT)
		{
			if (data->map_content.collectible_found == 0)
				exit(1); /*AJOUTER ECRAN DE WIN ET FREE TOUT CE QUI A ETE ALLOUE*/
		}
		else if (data->map[data->player_pos.y][data->player_pos.x - 1] == GROUND)
		{
			data->map[data->player_pos.y][data->player_pos.x] = GROUND;
		}
		data->map[data->player_pos.y][data->player_pos.x - 1] = PLAYER;
		data->player_pos.x -= 1;
	}
}

static void	move_right(t_mlx_data *data)
{
	if (data->map[data->player_pos.y][data->player_pos.x + 1] != WALL)
	{
		if (data->map[data->player_pos.y][data->player_pos.x + 1] == COLLECTIBLE)
		{
			data->map[data->player_pos.y][data->player_pos.x] = GROUND;
			data->map_content.collectible_found -= 1;
		}
		else if (data->map[data->player_pos.y][data->player_pos.x + 1] == EXIT)
		{
			if (data->map_content.collectible_found == 0)
				exit(1); /*AJOUTER ECRAN DE WIN ET FREE TOUT CE QUI A ETE ALLOUE*/
		}
		else if (data->map[data->player_pos.y][data->player_pos.x + 1] == GROUND)
		{
			data->map[data->player_pos.y][data->player_pos.x] = GROUND;
		}
		data->map[data->player_pos.y][data->player_pos.x + 1] = PLAYER;
		data->player_pos.x += 1;
	}
}

static void	move_up(t_mlx_data *data)
{
	if (data->map[data->player_pos.y - 1][data->player_pos.x] != WALL)
	{
		if (data->map[data->player_pos.y - 1][data->player_pos.x] == COLLECTIBLE)
		{
			data->map[data->player_pos.y][data->player_pos.x] = GROUND;
			data->map_content.collectible_found -= 1;
		}
		else if (data->map[data->player_pos.y - 1][data->player_pos.x] == EXIT)
		{
			if (data->map_content.collectible_found == 0)
				exit(1); /*AJOUTER ECRAN DE WIN ET FREE TOUT CE QUI A ETE ALLOUE*/
		}
		else if (data->map[data->player_pos.y - 1][data->player_pos.x] == GROUND)
		{
			data->map[data->player_pos.y][data->player_pos.x] = GROUND;
		}
		data->map[data->player_pos.y - 1][data->player_pos.x] = PLAYER;
		data->player_pos.y -= 1;
	}
}

int	handle_input(int keycode, t_mlx_data *data)
{
	printf("Movements: %d\n", keycode);
	ft_printf("Player position: %d, %d\n", data->player_pos.x, data->player_pos.y);
	if (keycode == XK_Escape)
		exit(1);
	else if (keycode == XK_w)
	{
		ft_printf("Player position: %d, %d\n", data->player_pos.x, data->player_pos.y);
		move_up(data);
	}
	else if (keycode == XK_s)
	{
		ft_printf("Player position: %d, %d\n", data->player_pos.x, data->player_pos.y);
		move_down(data);
	}
	else if (keycode == XK_a)
	{
		ft_printf("Player position: %d, %d\n", data->player_pos.x, data->player_pos.y);
		move_left(data);
	}
	else if (keycode == XK_d)
	{
		ft_printf("Player position: %d, %d\n", data->player_pos.x, data->player_pos.y);
		move_right(data);
	}
	return (0);
}