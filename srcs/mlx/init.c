/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdibia <opdibia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:33:55 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/16 20:40:00 by opdibia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	refresh_player(t_game *game, int x, int y)
{
	game->player.pos_x = x;
	game->player.pos_y = y;
	game->player.ray_x = x;
	game->player.ray_y = y;
}
void	init(t_game *game)
{
	t_player player;

	player.dir_x = -1;
	player.dir_y = 0;
	player.plane_x = 0;
	player.plane_y = 0.66;
	game->mlx.start_x = 0;
	game->mlx.start_y = 0;
	game->mlx.end_x = 0;
	game->mlx.end_y = 0;
	player.ray_dir_x = 0;
	player.ray_dir_y = 0;
    if(game->config->player_dir == 'N')
	{
       player.ray_dir_y = -1;
	   player.ray_dir_x = 0;
	}
	else if(game->config->player_dir == 'S')
	{
       player.ray_dir_y = 1;
	   player.ray_dir_x = 0;
	}
    if(game->config->player_dir == 'W')
	{
       player.ray_dir_y = 0;
	   player.ray_dir_x = -1;
	}
    else if(game->config->player_dir == 'E')
	{
       player.ray_dir_y = 0;
	   player.ray_dir_x = 1;
	}
    player.delta_dist_x = fabs(1/player.ray_dir_x);
    player.delta_dist_y = fabs(1/player.ray_dir_y);
	game->player = player;
}