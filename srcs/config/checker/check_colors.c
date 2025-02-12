/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:57:02 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 11:14:14 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	check_color_format(t_color color)
{
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
	{
		ft_putstr_fd("Error\nColor values must be between 0 and 255\n", 2);
		return (1);
	}
	return (0);
}

static int	check_color_value(t_color color)
{
	if (color.r == -1 || color.g == -1 || color.b == -1)
	{
		ft_putstr_fd("Error\nMissing color information\n", 2);
		return (1);
	}
	return (0);
}

int	check_colors(t_config *config)
{
	if (check_color_value(config->floor_color)
		|| check_color_value(config->ceiling_color))
		return (1);
	if (check_color_format(config->floor_color)
		|| check_color_format(config->ceiling_color))
		return (1);
	return (0);
}
