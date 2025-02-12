/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:17:29 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 17:12:05 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	put_error(char *mess)
{
	ft_putstr_fd(mess, 2);
	return (1);
}

static int	check_char(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (put_error("Error\nInvalid character in map\n"));
			if (is_valid_player(map[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (put_error("Error\nOnly one position (N, S, E, W)\n"));
	return (0);
}

int	check_map(t_config *config)
{
	if (check_char(config->map))
		return (1);
	if (check_wall(config->map))
		return (1);
	return (0);
}
