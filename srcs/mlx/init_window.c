/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdibia <opdibia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:59:52 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/16 20:39:13 by opdibia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <time.h>

int	close_window(t_game *game, int status)
{
	(void)status;
	if (game->mlx.win)
	{
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
	}
	if (game->mlx.mlx)
		mlx_destroy_display(game->mlx.mlx);
	if (game->mlx.mlx)
		free(game->mlx.mlx);
	free_config(game->config);
	exit(status);
}
static int 	handle_key_release(int keycode, t_game *game)
{
	(void)game;
	(void)keycode;
	return(0);
}

static int	key_press(int keycode, t_game *game)
{
	double angle = 0.5;
	if (keycode == XK_Right)
	{
		double oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-angle) - game->player.dir_y * sin(-angle);
		game->player.dir_y = oldDirX * sin(-angle) + game->player.dir_y * cos(-angle);
		double oldPlaneX = game->player.plane_x;
      game->player.plane_x = game->player.plane_x * cos(-angle) - game->player.plane_y * sin(-angle);
      game->player.plane_y = oldPlaneX * sin(-angle) + game->player.plane_y * cos(-angle);
		return (1);
	}
	else if (keycode == XK_Left)
	{
		double oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
		game->player.dir_y = oldDirX * sin(angle) + game->player.dir_y * cos(angle);
		double oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(angle) - game->player.plane_y * sin(angle);
		game->player.plane_y = oldPlaneX * sin(angle) + game->player.plane_y * cos(angle);
		return (1);
	}
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

static int	handle_key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		close_window(param, 0);
	game->player.new_x = game->player.pos_x;
	game->player.new_y = game->player.pos_y;
	if (key_press(keycode, game) == 1)
		move_player(game);
	return (0);
}

static void	handle_error(t_game *game, char *error, int i)
{
	ft_putstr_fd(error, 2);
	if (i == 1 || i == 3)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (i == 2 || i == 3)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
	if (game->mlx.mlx)
		mlx_destroy_display(game->mlx.mlx);
	if (game->mlx.mlx)
		free(game->mlx.mlx);
	free_config(game->config);
	exit(EXIT_FAILURE);
}

void	set_window(t_config *config)
{
	t_game	game;
	
	game.config = config;
	game.mlx.mlx = mlx_init();
	if (!game.mlx.mlx)
		handle_error(&game, "Error\nmlx init\n", 0);
	game.mlx.win = mlx_new_window(game.mlx.mlx, WIDTH, HEIGHT, "Cub3D");
	if (game.mlx.win == NULL)
		handle_error(&game, "Error\nmlx window\n", 1);
	game.mlx.img = mlx_new_image(game.mlx.mlx, WIDTH, HEIGHT);
	if (game.mlx.img == NULL)
		handle_error(&game, "Error\nmlx image\n", 2);
	game.mlx.addr = mlx_get_data_addr(game.mlx.img, &game.mlx.bits_per_pixel,
		&game.mlx.line_length, &game.mlx.endian);
	if (!game.mlx.addr)
		handle_error(&game, "Error\nmlx addr\n", 3);
	get_map_size(&game);
	init(&game);
	draw(&game);
	set_ray(&game);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_hook(game.mlx.win, 02, (1L<<0), handle_key_press, &game);
	mlx_hook(game.mlx.win, 03, (1L<<1), handle_key_release, &game);
	mlx_loop(game.mlx.mlx);
}
