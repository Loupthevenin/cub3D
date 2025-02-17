/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:10:59 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/17 19:27:19 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	exit_config(t_config *config, char **file_content)
{
	if (file_content)
		free_tab((void **)file_content, 0, 1);
	if (config)
		free_config(config);
	exit(EXIT_FAILURE);
}

static int	count_map_lines(char **file_content, int index_map)
{
	int	count;

	count = 0;
	while (file_content[index_map])
	{
		if (ft_strlen(file_content[index_map]) > 0)
			count++;
		index_map++;
	}
	return (count);
}

static void	parse_map(t_config *config, char **file_content, int index_map)
{
	int	i;
	int	size_map;

	i = 0;
	size_map = count_map_lines(file_content, index_map);
	config->map = (char **)malloc(sizeof(char *) * (size_map + 1));
	if (!config->map)
	{
		ft_putstr_fd("Error\nAlloc map\n", 2);
		exit_config(config, file_content);
	}
	while (file_content[index_map])
	{
		if (ft_strlen(file_content[index_map]) > 0)
			config->map[i++] = ft_strdup(file_content[index_map]);
		index_map++;
	}
	config->map[i] = NULL;
}

static void	set_default_values(t_config *config)
{
	config->map = NULL;
	config->floor_color.r = -1;
	config->floor_color.g = -1;
	config->floor_color.b = -1;
	config->ceiling_color.r = -1;
	config->ceiling_color.g = -1;
	config->ceiling_color.b = -1;
	config->texture_n = NULL;
	config->texture_s = NULL;
	config->texture_e = NULL;
	config->texture_w = NULL;
}

void	init_config(t_config *config, const char *path)
{
	char	**file_content;
	int		index_map;

	if (check_path(path))
		exit(EXIT_FAILURE);
	file_content = read_file(path);
	if (!file_content)
		exit(EXIT_FAILURE);
	set_default_values(config);
	if (check_unique_texture_colors(file_content))
		exit_config(config, file_content);
	index_map = parse_texture_colors(config, file_content);
	if (check_texture(config))
		exit_config(config, file_content);
	if (check_colors(config))
		exit_config(config, file_content);
	parse_map(config, file_content, index_map);
	if (check_map(config))
		exit_config(config, file_content);
	parse_player_pos(config, config->map);
	parse_size_map(config, config->map);
	free_tab((void **)file_content, 0, 1);
}
