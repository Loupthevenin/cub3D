/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:05:23 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 18:13:22 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_config
{
	char	*texture_n;
	char	*texture_s;
	char	*texture_e;
	char	*texture_w;
	t_color	floor_color;
	t_color	ceiling_color;
	char	**map;
	int		map_height;
	int		map_weight;
	int		player_x;
	int		player_y;
	char	player_dir;
}			t_config;

// Utils
void		free_tab(void **tabs, int size, int is_null);
int			ft_len_tab(char **tab);
void		free_config(t_config *config);
int			is_valid_char(char c);
int			is_valid_player(char c);
char		**map_dup(char **map, int size);

// Parsing
void		init_config(t_config *config, const char *path);
int			check_path(const char *path);
char		**read_file(const char *path);
int			parse_texture_colors(t_config *config, char **file_content);
int			check_texture(t_config *config);
int			check_colors(t_config *config);
int			check_map(t_config *config);
int			check_wall(char **map);

#endif
