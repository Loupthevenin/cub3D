/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unique_texture_colors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:27:37 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/17 19:39:33 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	check_unique(int *count)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (count[i] > 1)
		{
			ft_putstr_fd("Error\nOnly unique value: NO SO WE EA F C\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_unique_texture_colors(char **file_content)
{
	int	i;
	int	count[6];

	i = 0;
	while (i < 6)
		count[i++] = 0;
	i = 0;
	while (file_content[i])
	{
		if (!ft_strncmp(file_content[i], "NO ", 3))
			count[0]++;
		else if (!ft_strncmp(file_content[i], "SO ", 3))
			count[1]++;
		else if (!ft_strncmp(file_content[i], "WE ", 3))
			count[2]++;
		else if (!ft_strncmp(file_content[i], "EA ", 3))
			count[3]++;
		else if (!ft_strncmp(file_content[i], "F ", 2))
			count[4]++;
		else if (!ft_strncmp(file_content[i], "C ", 2))
			count[5]++;
		i++;
	}
	return (check_unique(count));
}
