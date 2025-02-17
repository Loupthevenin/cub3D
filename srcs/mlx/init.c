/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:33:55 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/17 16:29:48 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_dir(t_game *game, t_player *player)
{
	if (game->config->player_dir == 'N' || game->config->player_dir == 'S')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
		player->dir_x = 0;
	}
	if (game->config->player_dir == 'W' || game->config->player_dir == 'E')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
		player->dir_y = 0;
	}
	if (game->config->player_dir == 'N')
		player->dir_y = -1;
	else if (game->config->player_dir == 'S')
		player->dir_y = 1;
	if (game->config->player_dir == 'W')
		player->dir_x = -1;
	else if (game->config->player_dir == 'E')
		player->dir_x = 1;
}

void	init(t_game *game)
{
	t_player	player;

	set_dir(game, &player);
	get_tiles_size(game);
	game->player = player;
	game->mlx.start_x = 0;
	game->mlx.start_y = 0;
	game->mlx.end_x = 0;
	game->mlx.end_y = 0;
	player.ray_dir_x = 0;
	player.ray_dir_y = 0;
}
