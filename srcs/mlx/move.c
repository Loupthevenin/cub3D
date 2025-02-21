/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:41:58 by opdibia           #+#    #+#             */
/*   Updated: 2025/02/21 11:52:53 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player(t_game *game)
{
	if (game->config->map[(int)game->player.new_y][(int)game->player.new_x] != '1')
	{
		if (game->config->map[(int)game->player.pos_y][(int)game->player.pos_x] == game->config->player_dir)
			game->config->map[(int)game->player.pos_y][(int)game->player.pos_x] = '0';
		game->player.pos_x = game->player.new_x;
		game->player.pos_y = game->player.new_y;
	}
	draw(game);
}

int	move_up_down(int keycode, t_game *game, double move_speed)
{
	if (keycode == XK_s)
	{
		if (game->config->map[(int)(game->player.pos_y - (game->player.dir_y
					* move_speed * 2))][(int)(game->player.pos_x)] == '0')
			game->player.new_y -= (game->player.dir_y * move_speed);
		if (game->config->map[(int)(game->player.pos_y)][(int)(game->player.pos_x
				- (game->player.dir_x * move_speed * 2))] == '0')
			game->player.new_x -= (game->player.dir_x * move_speed);
		return (1);
	}
	else if (keycode == XK_w)
	{
		if (game->config->map[(int)(game->player.pos_y + (game->player.dir_y
					* move_speed * 2))][(int)(game->player.pos_x)] == '0')
			game->player.new_y += (game->player.dir_y * move_speed);
		if (game->config->map[(int)(game->player.pos_y)][(int)(game->player.pos_x
				+ (game->player.dir_x * move_speed * 2))] == '0')
			game->player.new_x += (game->player.dir_x * move_speed);
		return (1);
	}
	return (0);
}

int	move_left_right(int keycode, t_game *game, double move_speed)
{
	if (keycode == XK_a)
	{
		if (game->config->map[(int)(game->player.pos_y)][(int)(game->player.pos_x
				+ (game->player.dir_y * move_speed * 2))] == '0')
			game->player.new_x += (game->player.dir_y * move_speed);
		if (game->config->map[(int)(game->player.pos_y - (game->player.dir_x
					* move_speed * 2))][(int)(game->player.new_x)] == '0')
			game->player.new_y -= (game->player.dir_x * move_speed);
		return (1);
	}
	else if (keycode == XK_d)
	{
		if (game->config->map[(int)(game->player.pos_y)][(int)(game->player.pos_x
				- (game->player.dir_y * move_speed * 2))] == '0')
			game->player.new_x -= (game->player.dir_y * move_speed);
		if (game->config->map[(int)(game->player.pos_y + (game->player.dir_x
					* move_speed * 2))][(int)(game->player.new_x)] == '0')
			game->player.new_y += (game->player.dir_x * move_speed);
		return (1);
	}
	return (0);
}

int	player_move(int keycode, t_game *game)
{
	double	move_speed;

	move_speed = 0.5;
	if (move_up_down(keycode, game, move_speed) == 1)
		return (1);
	if (move_left_right(keycode, game, move_speed) == 1)
		return (1);
	return (0);
}
