/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:36 by crystal           #+#    #+#             */
/*   Updated: 2024/07/12 22:16:57 by crystal          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_mlx_data	*data;

	data = ft_calloc(1, sizeof(t_mlx_data));
	check_args(argc, argv, data);
	init_map_content(data);
	get_map(argv, data);
	ft_mlx_init(data, data->rows, data->cols);
	// data->win = mlx_new_window(data->mlx, 1250, 720, "so_long");
	// if (!data->win)
	// {
	// 	mlx_destroy_display(data->mlx);
	// 	return (free(data->mlx), 1);
	// }
	// mlx_key_hook(data->win, handle_input, &data);
	// print_image(data, "assets/AnyConv.com__grounds.xpm", 100, 100);
	// printf("Window created, count = %d\n", data->count);
	// mlx_loop(data->mlx);
	end_prog(data);
	return (0);
}