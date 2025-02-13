/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:05:23 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/13 13:03:03 by opdi-bia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 820
# define HEIGHT 820

# define GREEN_PIXEL 0xFF00
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_config
{
	char		*texture_n;
	char		*texture_s;
	char		*texture_e;
	char		*texture_w;
	t_color		floor_color;
	t_color		ceiling_color;
	char		**map;
	int			map_height;
	int			map_width;
	int			player_x;
	int			player_y;
	char		player_dir;
	// float time;
	// float oldtime;
}				t_config;

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	int			new_x;
	int			new_y;
	float		ray_x;
	float		ray_y;
	float		ray_dir_x;
	float		ray_dir_y;
}				t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*addr;
	float		tileswidth;
	float		tilesheight;
}				t_mlx;

typedef struct s_game
{
	t_mlx		mlx;
	t_config	*config;
	t_player	player;
}				t_game;

// Utils
void			free_tab(void **tabs, int size, int is_null);
int				ft_len_tab(char **tab);
void			free_config(t_config *config);
int				is_valid_char(char c);
int				is_valid_player(char c);
char			**map_dup(char **map, int size);

// Parsing
void			init_config(t_config *config, const char *path);
int				check_path(const char *path);
char			**read_file(const char *path);
int				parse_texture_colors(t_config *config, char **file_content);
int				check_texture(t_config *config);
int				check_colors(t_config *config);
int				check_map(t_config *config);
int				check_wall(char **map);
void			parse_player_pos(t_config *config, char **map);

//mlx
void			set_window(t_config *config);
void			draw(t_game *game);
void			move_player(t_game *game);
void			set_ray(t_game *game);

#endif
