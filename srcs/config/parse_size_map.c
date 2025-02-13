/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:46:05 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/13 15:56:29 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_width(char **map)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (result < j)
			result = j;
		i++;
	}
	return (result);
}

void	parse_size_map(t_config *config, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	config->map_height = i;
	config->map_width = get_width(map);
}
