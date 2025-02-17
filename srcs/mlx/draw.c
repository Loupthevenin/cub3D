/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:53:07 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/17 17:07:02 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw(t_game *game)
{
	draw_map(game);
	mlx_clear_window(game->mlx.mlx, game->mlx.win);
	cast_ray(game);
}
