/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:02:58 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 20:12:44 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_player_pos(t_config *config, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_valid_player(map[y][x]))
			{
				config->player_y = y;
				config->player_x = x;
				config->player_dir = map[y][x];
				return ;
			}
			x++;
		}
		y++;
	}
}
