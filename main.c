/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:36 by crystal           #+#    #+#             */
/*   Updated: 2024/07/17 20:15:24 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	*file_to_image(t_mlx_data *data, char *path, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
	if (!img)
	{
		free_map(data->map);
		exit(1);
	}
	return (img);	
}

void	ft_init_sprites(t_mlx_data *data)
{
	int	x;
	int	y;

	x = data->img.x;
	y = data->img.y;
	data->img.ground2 = file_to_image(data, GROUND_PATH, x, y);
	data->img.chest_closed = file_to_image(data, COLLECTIBLE_PATH, x, y);
	data->img.wall = file_to_image(data, WALL_PATH, x, y);
	data->img.exit_closed = file_to_image(data, EXIT_CL_PATH, x, y);
	data->img.exit_open = file_to_image(data, EXIT_OP_PATH, x, y);
	data->img.player_back = file_to_image(data, PLAYER_BA_PATH, x, y);
	data->img.player_left = file_to_image(data, PLAYER_LE_PATH, x, y);
	data->img.player_front = file_to_image(data, PLAYER_FR_PATH, x, y);
	data->img.player_right = file_to_image(data, PLAYER_RI_PATH, x, y);
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
	render_map(data->mlx);
	mlx_hook(data->win, 3, 2, handle_input, data);
	mlx_hook(data->win, 17, 0, end, data);
	mlx_hook(data->win, 12, 32768, make_mouv, data);
	printf("Window created, count = %d\n", data->count);
	mlx_loop(data->mlx);
	free_all(data);
	return (0);
}
