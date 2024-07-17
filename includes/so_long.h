/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:08:50 by crystal           #+#    #+#             */
/*   Updated: 2024/07/17 20:10:34 by crystal          ###   ########.fr       */
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

#define WALL_PATH "sprites/Walls.xpm"
#define EXIT_CL_PATH "sprites/Door_closed.xpm"
#define EXIT_OP_PATH "sprites/Door_open.xpm"
#define COLLECTIBLE_PATH "sprites/coin.xpm"
#define PLAYER_FR_PATH "sprites/Warrior_front.xpm"
#define PLAYER_BA_PATH "sprites/Warior_back.xpm"
#define PLAYER_LE_PATH "sprites/Warrior_left.xpm"
#define PLAYER_RI_PATH "sprites/Warrior_right.xpm"
#define GROUND_PATH "sprites/Grass2.xpm"


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
	int			y;
	int			x;
	
	void		*ground1;
	void		*ground2;
	void		*wall;
	void		*exit_closed;
	void		*exit_open;
	void		*chest_closed;
	void		*chest_open;
	void		*player_front;
	void		*player_back;
	void		*player_left;
	void		*player_right;

}		t_img;

typedef struct s_pos
{
	int		x;
	int		y;
}		t_pos;

typedef struct s_mlx_data
{
	int		height;
	int		width;
	int		count;
	int		rows;
	int		cols;
	int		movements;
	bool	map_allocated;
	char 	**map;
	void	*mlx;
	void	*win;
	t_img	img;
	t_map_content	map_content;
	t_pos	pos;
}		t_mlx_data;

/* 		INPUTS 		*/
int	handle_input(int keycode, t_mlx_data *data);
void	check_args(int argc, char **argv, t_mlx_data *data);

/*		ERRORS/END		*/
int	ft_error(char *str, t_mlx_data *data);
void	free_map(char **map);
void	end_prog(t_mlx_data *data);
void	free_all(t_mlx_data *data);
void	ft_close_all(t_mlx_data *data);
int	end(t_mlx_data *data);

/*		INIT		*/
int			is_valid_content(char c, t_map_content map_content);
void	init_map_content(t_mlx_data *data);
void	check_map(t_mlx_data *data);
void	get_map(char **argv, t_mlx_data *data);
void	ft_mlx_init(t_mlx_data *data);
void	*file_to_image(t_mlx_data *data, char *path, int x, int y);
void	print_image(t_mlx_data *data, char *path, int x, int y);
t_img	ft_image(void *mlx, char *path, t_mlx_data *data);

/*		RENDER		*/
int		make_mouv(t_mlx_data *data);
void	render_map(t_mlx_data *data);
void	you_win(t_mlx_data *data);
void	new_exit(t_mlx_data *data);
void	new_player(t_mlx_data *data, char *path);

#endif