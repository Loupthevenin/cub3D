/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:33:55 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/21 11:34:27 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_dir(t_game *game, t_player *player)
{
	if (game->config->player_dir == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (game->config->player_dir == 'W')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
		player->dir_x = -1;
		player->dir_y = 0;
	}
	if (game->config->player_dir == 'S')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (game->config->player_dir == 'E')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
		player->dir_x = 1;
		player->dir_y = 0;
	}
	// if (game->config->player_dir == 'N')
	// 	player->dir_y = -1;
	// else if (game->config->player_dir == 'S')
	// 	player->dir_x = -1;
	// if (game->config->player_dir == 'W')
	// 	player->dir_y = 1;
	// else if (game->config->player_dir == 'E')
	// 	player->dir_x = 1;
}

static void	load_texture(t_game *game, t_texture *texture, char *path, int i)
{
	texture->img = mlx_xpm_file_to_image(game->mlx.mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		ft_putstr_fd("Error\nload XPM failed\n", 2);
		close_window(game, EXIT_FAILURE, i);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
}

static void	init_textures(t_game *game)
{
	load_texture(game, &game->mlx.textures[0], game->config->texture_n, 0);
	load_texture(game, &game->mlx.textures[1], game->config->texture_s, 1);
	load_texture(game, &game->mlx.textures[2], game->config->texture_e, 2);
	load_texture(game, &game->mlx.textures[3], game->config->texture_w, 3);
}

void	init(t_game *game)
{
	t_player	player;

	set_dir(game, &player);
	get_tiles_size(game);
	player.pos_x = game->config->player_x;
	player.pos_y = game->config->player_y;
	game->mlx.start_x = 0;
	game->mlx.start_y = 0;
	game->mlx.end_x = 0;
	game->mlx.end_y = 0;
	game->player = player;
	init_textures(game);
}
