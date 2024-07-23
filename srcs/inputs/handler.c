/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:19:52 by crystal           #+#    #+#             */
/*   Updated: 2024/07/22 07:17:17 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_down(t_mlx_data *data)
{
	if (data->map[data->pos.y + 1][data->pos.x] != WALL)
	{
		data->movements += 1;
		if (data->map[data->pos.y + 1][data->pos.x] == COLLECTIBLE)
		{
			data->map[data->pos.y][data->pos.x] = GROUND;
			data->map_content.collectible_found -= 1;
			new_exit(data);
		}
		else if (data->map[data->pos.y + 1][data->pos.x] == EXIT)
		{
			if (data->map_content.collectible_found == 0)
				you_win(data);
		}
		else if (data->map[data->pos.y + 1][data->pos.x] == GROUND)
			data->map[data->pos.y][data->pos.x] = GROUND;
		if (data->map[data->pos.y + 1][data->pos.x] != EXIT)
		{
			data->map[data->pos.y + 1][data->pos.x] = PLAYER;
			data->pos.y += 1;
		}
		ft_printf("%d\n", data->movements);
	}
	new_player(data, PLAYER_FR_PATH);
	render_map(data);
}

static void	move_left(t_mlx_data *data)
{
	if (data->map[data->pos.y][data->pos.x - 1] != WALL)
	{
		data->movements += 1;
		if (data->map[data->pos.y][data->pos.x - 1] == COLLECTIBLE)
		{
			data->map[data->pos.y][data->pos.x] = GROUND;
			data->map_content.collectible_found -= 1;
			new_exit(data);
		}
		else if (data->map[data->pos.y][data->pos.x - 1] == EXIT)
		{
			if (data->map_content.collectible_found == 0)
				you_win(data);
		}
		else if (data->map[data->pos.y][data->pos.x - 1] == GROUND)
			data->map[data->pos.y][data->pos.x] = GROUND;
		if (data->map[data->pos.y][data->pos.x - 1] != EXIT)
		{
			data->map[data->pos.y][data->pos.x - 1] = PLAYER;
			data->pos.x -= 1;
		}
		ft_printf("%d\n", data->movements);
	}
	new_player(data, PLAYER_LE_PATH);
	render_map(data);
}

static void	move_right(t_mlx_data *data)
{
	if (data->map[data->pos.y][data->pos.x + 1] != WALL)
	{
		data->movements += 1;
		if (data->map[data->pos.y][data->pos.x + 1] == COLLECTIBLE)
		{
			data->map[data->pos.y][data->pos.x] = GROUND;
			data->map_content.collectible_found -= 1;
			new_exit(data);
		}
		else if (data->map[data->pos.y][data->pos.x + 1] == EXIT)
		{
			if (data->map_content.collectible_found == 0)
				you_win(data);
		}
		else if (data->map[data->pos.y][data->pos.x + 1] == GROUND)
			data->map[data->pos.y][data->pos.x] = GROUND;
		if (data->map[data->pos.y][data->pos.x + 1] != EXIT)
		{
			data->map[data->pos.y][data->pos.x + 1] = PLAYER;
			data->pos.x += 1;
		}
		ft_printf("%d\n", data->movements);
	}
	new_player(data, PLAYER_RI_PATH);
	render_map(data);
}

static void	move_up(t_mlx_data *data)
{
	if (data->map[data->pos.y - 1][data->pos.x] != WALL)
	{
		data->movements += 1;
		if (data->map[data->pos.y - 1][data->pos.x] == COLLECTIBLE)
		{
			data->map[data->pos.y][data->pos.x] = GROUND;
			data->map_content.collectible_found -= 1;
			new_exit(data);
		}
		else if (data->map[data->pos.y - 1][data->pos.x] == EXIT)
		{
			if (data->map_content.collectible_found == 0)
				you_win(data);
		}
		else if (data->map[data->pos.y - 1][data->pos.x] == GROUND)
			data->map[data->pos.y][data->pos.x] = GROUND;
		if (data->map[data->pos.y - 1][data->pos.x] != EXIT)
		{
			data->map[data->pos.y - 1][data->pos.x] = PLAYER;
			data->pos.y -= 1;
		}
		ft_printf("%d\n", data->movements);
	}
	new_player(data, PLAYER_BA_PATH);
	render_map(data);
}

int	handle_input(int keycode, t_mlx_data *data)
{
	if (keycode == XK_Escape)
		end(data);
	if (keycode == XK_w)
		move_up(data);
	else if (keycode == XK_s)
		move_down(data);
	else if (keycode == XK_a)
		move_left(data);
	else if (keycode == XK_d)
		move_right(data);
	return (0);
}
