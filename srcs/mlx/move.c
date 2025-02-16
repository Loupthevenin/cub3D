/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:41:58 by opdibia           #+#    #+#             */
/*   Updated: 2025/02/17 16:29:42 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_value(t_game *game, int new_x, int new_y)
{
	game->config->map[new_y][new_x] = game->config->player_dir;
	if ((int)game->player.pos_x != new_x || (int)game->player.pos_y != new_y)
		game->config->map[(int)game->player.pos_y][(int)game->player.pos_x] = '0';
	game->player.pos_x = new_x;
	game->player.pos_y = new_y;
}

void	move_player(t_game *game)
{
	t_player	player;
	t_config	*config;

	config = game->config;
	player = game->player;
	if (config->map[(int)player.new_y][(int)player.new_x] != '1')
	{
		set_value(game, player.new_x, player.new_y);
	}
	draw(game);
}
