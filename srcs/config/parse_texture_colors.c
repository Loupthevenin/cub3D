/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:35:24 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 09:43:48 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	parse_color(t_color *color, char *content, t_config *config)
{
	char	**rgb;

	rgb = ft_split(content, ',');
	if (!rgb || ft_len_tab(rgb) != 3)
	{
		ft_putstr_fd("Error\nInvalid color format\n", 2);
		free_tab((void **)rgb, 0, 1);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_tab((void **)rgb, 0, 1);
}

static void	handle_texture(t_config *config, char *content, int *count_elements)
{
	if (!ft_strncmp(content, "NO ", 3))
	{
		config->texture_n = ft_strdup(content + 3);
		(*count_elements)++;
	}
	else if (!ft_strncmp(content, "SO ", 3))
	{
		config->texture_s = ft_strdup(content + 3);
		(*count_elements)++;
	}
	else if (!ft_strncmp(content, "WE ", 3))
	{
		config->texture_w = ft_strdup(content + 3);
		(*count_elements)++;
	}
	else if (!ft_strncmp(content, "EA ", 3))
	{
		config->texture_e = ft_strdup(content + 3);
		(*count_elements)++;
	}
}

static void	handle_colors(t_config *config, char *content, int *count_elements)
{
	if (!ft_strncmp(content, "F ", 2))
	{
		parse_color(&config->floor_color, content + 2, config);
		(*count_elements)++;
	}
	else if (!ft_strncmp(content, "C ", 2))
	{
		parse_color(&config->ceiling_color, content + 2, config);
		(*count_elements)++;
	}
}

int	parse_texture_colors(t_config *config, char **file_content)
{
	int	i;
	int	count_elements;

	i = 0;
	count_elements = 0;
	while (file_content[i])
	{
		handle_texture(config, file_content[i], &count_elements);
		handle_colors(config, file_content[i], &count_elements);
		i++;
		if (count_elements == 6)
			break ;
	}
	return (i);
}
