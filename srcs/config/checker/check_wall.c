/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:03:25 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 18:39:12 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	get_line_length(char **map, int y)
{
	int	i;

	i = 0;
	while (map[y] && map[y][i])
		i++;
	return (i);
}

static int	flood_fill(char **map, int y, int x)
{
	int	line_length;
	int	result;

	if (y < 0 || !map[y])
		return (1);
	line_length = get_line_length(map, y);
	if (x < 0 || x >= line_length || map[y][x] == ' ')
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	map[y][x] = 'V';
	result = 0;
	result += flood_fill(map, y - 1, x);
	result += flood_fill(map, y + 1, x);
	result += flood_fill(map, y, x - 1);
	result += flood_fill(map, y, x + 1);
	return (result);
}

static int	loop_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && flood_fill(map, i, j))
			{
				ft_putstr_fd("Error\nOpen map !!!\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_wall(char **map)
{
	int		rows;
	char	**dup_map;

	rows = 0;
	while (map[rows])
		rows++;
	dup_map = map_dup(map, rows);
	if (!dup_map)
	{
		return (1);
	}
	if (loop_walls(dup_map))
	{
		free_tab((void **)dup_map, 0, 1);
		return (1);
	}
	free_tab((void **)dup_map, 0, 1);
	return (0);
}
