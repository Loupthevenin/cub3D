/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdibia <opdibia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:18:10 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/23 20:02:29 by opdibia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_key_release(int keycode, t_game *game)
{
	(void)game;
	(void)keycode;
	return (0);
}

void	update_dir(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y
		* sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y
		* cos(angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y
		* cos(angle);
}

int	key_press(int keycode, t_game *game)
{
	double	angle;

	angle = 0.033 * 1.8;
	if (keycode == XK_Left)
	{
		update_dir(game, -angle);
		return (1);
	}
	else if (keycode == XK_Right)
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
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		close_window(param, 0, 3);
	game->player.new_x = game->player.pos_x;
	game->player.new_y = game->player.pos_y;
	if (key_press(keycode, game) == 1)
		move_player(game);
	return (0);
}
