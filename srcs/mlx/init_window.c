/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:59:52 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/21 11:35:54 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(t_game *game, int status, int i)
{
	if (game->mlx.mlx)
	{
		while (i >= 0)
		{
			if (game->mlx.textures[i].img)
				mlx_destroy_image(game->mlx.mlx, game->mlx.textures[i].img);
			i--;
		}
	}
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
	init(&game);
	draw(&game);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_hook(game.mlx.win, 02, (1L << 0), handle_key_press, &game);
	mlx_hook(game.mlx.win, 03, (1L << 1), handle_key_release, &game);
	mlx_loop(game.mlx.mlx);
}
