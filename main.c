/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:36 by crystal           #+#    #+#             */
/*   Updated: 2024/07/11 19:12:17 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

int	main(void)
{
	t_mlx_data	data;

	// if (argc != 1)
	// {
	// 	write(2, "Error\nThis program take a map in argument\n", 6);
	// 	return (0);
	// }
	// else
	// {
		data.count = 0;
		data.mlx = mlx_init();
		if (!data.mlx)
			return (1);
		init_map_content(&(data.map_content));
		data.win = mlx_new_window(data.mlx, 1250, 720, "so_long");
		if (!data.win)
		{
			mlx_destroy_display(data.mlx);
			return (free(data.mlx), 1);
		}
		mlx_key_hook(data.win, handle_input, &data);
		print_image(&data, "assets/AnyConv.com__grounds.xpm", 100, 100);
		printf("Window created, count = %d\n", data.count);
		mlx_loop(data.mlx);
	// }
		end_prog(&data);
	return (0);
}