/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:36 by crystal           #+#    #+#             */
/*   Updated: 2024/07/16 15:54:07 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	*file_to_image(void *mlx, char *path, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &x, &y);
	if (!img)
	{
		printf("Error\n");
		exit(1);
	}
	return (img);
}

void	ft_init_sprites(t_mlx_data *data)
{
	data->img.ground1 = file_to_image(data->mlx, "sprites/tileset_arranged.xpm", data->img.x, data->img.y);
	data->img.ground2 = file_to_image(data->mlx, "sprites/tileset_arranged.xpm", data->img.x, data->img.y);
	data->img.chest_closed = file_to_image(data->mlx, "sprites/gbost-town.xpm", data->img.x, data->img.y);
	data->img.chest_open = file_to_image(data->mlx, "sprites/gbost-town.xpm", data->img.x, data->img.y);
	data->img.wall = file_to_image(data->mlx, "sprites/Walls.xpm", data->img.x, data->img.y);
	data->img.exit_closed =  file_to_image(data->mlx, "sprites/Door_closed.xpm", data->img.x, data->img.y);
	data->img.exit_open =  file_to_image(data->mlx, "sprites/Door_open.xpm", data->img.x, data->img.y);
	data->img.player_back =  file_to_image(data->mlx, "sprites/Warrior_back.xpm", data->img.x, data->img.y);
	data->img.player_left = file_to_image(data->mlx, "sprites/Warrior_left.xpm", data->img.x, data->img.y);
	data->img.player_front = file_to_image(data->mlx, "sprites/Warrior_front.xpm", data->img.x, data->img.y);
	data->img.player_right = file_to_image(data->mlx, "sprites/Warrior_right.xpm", data->img.x, data->img.y);
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

// void replace_transparent_pixels(void *img_ptr)
// {
// 	int width = 0;
// 	int height = 0;
//     int *data;
//     int bits_per_pixel;
//     int size_line;
//     int endian;

//     data = (int *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
//     for (int y = 0; y < height; y++) {
//         for (int x = 0; x < width; x++) {
//             int pixel = data[y * width + x];
//             if (pixel == TRANSPARENT_COLOR) { // Remplacer la couleur spécifiée par la couleur de fond
//                 data[y * width + x] = BACKGROUND_COLOR;
//             }
//         }
//     }
// }

int	main(int argc, char **argv)
{
	t_mlx_data	*data;

	data = ft_calloc(1, sizeof(t_mlx_data));
	check_args(argc, argv, data);
	init_map_content(data);
	get_map(argv, data);
	ft_mlx_init(data);
	ft_init_sprites(data);
	// replace_transparent_pixels(data);
	render_map(data->mlx);
	//mlx_put_image_to_window(data->mlx, data->win, data->img.player_front, 64, 64);
	//mlx_key_hook(data->win, handle_input, &data);
	mlx_hook(data->win, 3, 2, handle_input, data);
	mlx_hook(data->win, 17, 0, end, data);
	mlx_hook(data->win, 12, 32768, make_mouv, data);
// if ((x % 2 == 1 && y % 2 != 1) || (x % 2 != 1 && y % 2 == 1))
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