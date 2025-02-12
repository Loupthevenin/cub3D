/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:43:33 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 10:55:53 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	check_texture_path(char *path)
{
	int	fd;

	if (!path)
	{
		ft_putstr_fd("Error\nInvalid texture path\n", 2);
		return (1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCannot open texture: ", 2);
		ft_putendl_fd(path, 2);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_texture(t_config *config)
{
	if (check_texture_path(config->texture_n)
		|| check_texture_path(config->texture_s)
		|| check_texture_path(config->texture_e)
		|| check_texture_path(config->texture_w))
		return (1);
	return (0);
}
