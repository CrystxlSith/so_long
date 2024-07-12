/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:08:50 by crystal           #+#    #+#             */
/*   Updated: 2024/07/12 20:41:09 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdbool.h>

#define WALL '1'
#define EXIT 'E'
#define COLLECTIBLE 'C'
#define PLAYER 'P'
#define GROUND '0'

#define RED "\033[0;31m"
#define CYAN "\033[0;34m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"


typedef struct s_map_content
{
	char	wall;
	char	exit;
	char	collectible;
	char	player;
	char	ground;
	int	player_found;
	int	exit_found;
	int	collectible_found;
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
	bool	map_allocated;
	char 	**map;
	void	*mlx;
	void	*win;
	t_img	img;
	t_map_content	map_content;
	t_player_pos	player_pos;
}		t_mlx_data;

/* 		INPUTS 		*/
int	handle_input(int keycode, t_mlx_data *data);
void	check_args(int argc, char **argv, t_mlx_data *data);

/*		ERRORS		*/
char	**ft_error(char *str, t_mlx_data *data);
void	free_map(char **map);
void	end_prog(t_mlx_data *data);

/*		INIT		*/
void	init_map_content(t_mlx_data *data);
void	check_map(t_mlx_data *data);
void	get_map(char **argv, t_mlx_data *data);
int	is_valid_content(char c, t_map_content map_content);

#endif