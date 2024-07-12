/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:32:57 by crystal           #+#    #+#             */
/*   Updated: 2024/07/12 15:04:13 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**ft_error(char *str, t_mlx_data *data)
{
	ft_putstr_fd(str, 2);
	if (data->map_allocated == true)
		free_map(data->map);
	if (data)
		free(data);
	exit(1);
}