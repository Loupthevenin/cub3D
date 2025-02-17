/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:18:10 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/17 13:48:19 by opdi-bia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_key_release(int keycode, t_game *game)
{
	(void)game;
	(void)keycode;
	return (0);
}

void	update_dir(t_game *game, float angle)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y
		* sin(angle);
	game->player.dir_y = oldDirX * sin(angle) + game->player.dir_y * cos(angle);
	oldPlaneX = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = oldPlaneX * sin(angle) + game->player.plane_y
		* cos(angle);
}

int	player_move(int keycode, t_game *game)
{
	if (keycode == XK_d)
	{
		game->player.new_x += 1;
		return (1);
	}
	else if (keycode == XK_a)
	{
		game->player.new_x -= 1;
		return (1);
	}
	else if (keycode == XK_s)
	{
		game->player.new_y += 1;
		return (1);
	}
	else if (keycode == XK_w)
	{
		game->player.new_y -= 1;
		return (1);
	}
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	double	angle;

	angle = 0.15;
	if (keycode == XK_Right)
	{
		update_dir(game, -angle);
		return (1);
	}
	else if (keycode == XK_Left)
	{
		update_dir(game, angle);
		return (1);
	}
	if (player_move(keycode, game) == 1)
		return (1);
	return (0);
}

int	handle_key_press(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		close_window(param, 0);
	game->player.new_x = game->player.pos_x;
	game->player.new_y = game->player.pos_y;
	if (key_press(keycode, game) == 1)
		move_player(game);
	return (0);
}
