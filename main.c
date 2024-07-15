/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:36 by crystal           #+#    #+#             */
/*   Updated: 2024/07/13 21:45:26 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_init_sprites(t_mlx_data *data)
{
	data->img.ground1 = mlx_xpm_file_to_image(data->mlx, "sprites/Grass1.xpm", &data->img.x, &data->img.y);
	data->img.ground2 = mlx_xpm_file_to_image(data->mlx, "sprites/Grass2.xpm", &data->img.x, &data->img.y);
	data->img.chest_closed = mlx_xpm_file_to_image(data->mlx, "sprites/Chest_closed.xpm", &data->img.x, &data->img.y);
	data->img.chest_open = mlx_xpm_file_to_image(data->mlx, "sprites/Chest_open.xpm", &data->img.x, &data->img.y);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "sprites/Tree.xpm", &data->img.x, &data->img.y);
	data->img.exit_closed = mlx_xpm_file_to_image(data->mlx, "sprites/Door_closed.xpm", &data->img.x, &data->img.y);
	data->img.exit_open = mlx_xpm_file_to_image(data->mlx, "sprites/Door_open.xpm", &data->img.x, &data->img.y);
	data->img.player_back = mlx_xpm_file_to_image(data->mlx, "sprites/Warrior_back.xpm", &data->img.x, &data->img.y);
	data->img.player_left = mlx_xpm_file_to_image(data->mlx, "sprites/Warrior_left.xpm", &data->img.x, &data->img.y);
	data->img.player_front = mlx_xpm_file_to_image(data->mlx, "sprites/Warrior_front.xpm", &data->img.x, &data->img.y);
	data->img.player_right = mlx_xpm_file_to_image(data->mlx, "sprites/Warrior_right.xpm", &data->img.x, &data->img.y);
}

void	print_image(t_mlx_data *data, char *path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(data->mlx, path, &img_width, &img_height);
	if (!img)
	{
		printf("Error\n");
		exit(1);
	}
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}

int	main(int argc, char **argv)
{
	t_mlx_data	*data;

	data = ft_calloc(1, sizeof(t_mlx_data));
	check_args(argc, argv, data);
	init_map_content(data);
	get_map(argv, data);
	ft_mlx_init(data);
	ft_init_sprites(data);
	render_map(data);
	//mlx_put_image_to_window(data->mlx, data->win, data->img.player_front, 64, 64);
	mlx_key_hook(data->win, handle_input, &data);
	//print_image(data, "assets/.xpm", 100, 100);
	printf("Window created, count = %d\n", data->count);
	mlx_loop(data->mlx);
	// data->win = mlx_new_window(data->mlx, 1250, 720, "so_long");
	// if (!data->win)
	// {
	// 	mlx_destroy_display(data->mlx);
	// 	return (free(data->mlx), 1);
	// }
	// print_image(data, "assets/AnyConv.com__grounds.xpm", 100, 100);
	// printf("Window created, count = %d\n", data->count);
	// 
	
	free_all(data);
	return (0);
}