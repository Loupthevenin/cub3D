/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:52:15 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 17:03:17 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ' && c != '\t')
		return (0);
	return (1);
}

int	is_valid_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

char	**map_dup(char **map, int size)
{
	int		i;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = ft_strdup(map[i]);
		if (!result[i])
		{
			free_tab((void **)result, 0, 1);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
