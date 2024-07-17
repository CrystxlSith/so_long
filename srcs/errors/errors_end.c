/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:11:50 by crystal           #+#    #+#             */
/*   Updated: 2024/07/17 18:06:45 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_args(int argc, char **argv, t_mlx_data *data)
{
	data->map_allocated = false;
	if (argc != 2)
		ft_error(RED"Error\nThis program take a map in argument\n", data);
	if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		ft_error(RED"Error\nThis program take a .ber in argument\n"RESET, data);
}

void	end_prog(t_mlx_data *data)
{
	if (data->map_allocated == true)
		free_map(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}

void	you_win(t_mlx_data *data)
{
	ft_printf(GREEN"YOU WIN\n"RESET);
	ft_printf("Vous avez fait %d mouvements\n", data->movements);
	end(data);
	exit(0);
}

int	end(t_mlx_data *data)
{
	free_all(data);
	return (0);
}
