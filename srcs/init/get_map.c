/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:25:04 by crystal           #+#    #+#             */
/*   Updated: 2024/07/17 18:11:51 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	*ft_join_free(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	get_map(char **argv, t_mlx_data *data)
{
	int		fd;
	char	*map;
	char	*line;

	data->map = NULL;
	fd = open(argv[1], O_RDONLY);
	map = ft_calloc(1, sizeof(char));
	if (fd < 0 || !ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		ft_error("Error\nIncorrect map file\n", data);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_join_free(&map, line);
		ft_printf("%s\n", line);
		free(line);
	}
	data->map = ft_split(map, '\n');
	data->map_allocated = true;
	close(fd);
	free(map);
	check_map(data);
}
