/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:08:50 by crystal           #+#    #+#             */
/*   Updated: 2024/07/11 17:39:39 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_map_content
{
	char	wall;
	char	exit;
	char	collectible;
	char	player;
	char	ground;
}		t_map_content;


typedef struct s_img
{
	int		height;
	int		width;	
	void	*png_wall;
	void	*png_exit;
	void	*png_collectible;
	void	*png_player;
	void	*png_ground;
	char	*wall;
	char	*exit;
	char	*collectible;
	char	*player;
	char	*ground;

}		t_img;

typedef struct s_player_pos
{
	int		x;
	int		y;
}		t_player_pos;

typedef struct s_mlx_data
{
	int		height;
	int		width;	
	int		count;
	char 	**map;
	void	*mlx;
	void	*win;
	t_img	img;
	t_map_content	map_content;
	t_player_pos	player_pos;
}		t_mlx_data;

/* 		INPUTS 		*/
int	handle_input(int keycode, t_mlx_data *data);

/*		ERRORS		*/
void	end_prog(t_mlx_data *data);

/*		INIT		*/
void	init_map_content(t_map_content *content);

#endif