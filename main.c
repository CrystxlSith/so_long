/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:36 by crystal           #+#    #+#             */
/*   Updated: 2024/07/10 17:18:49 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_window = mlx_new_window(mlx, 1920, 1080, "so_long");
	if (!mlx_window)
		return (free(mlx), 1);
	free (mlx);
	return (0);
	mlx_loop(mlx);
}