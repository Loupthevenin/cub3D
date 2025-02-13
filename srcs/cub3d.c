/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:04:05 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/13 15:55:56 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	error_main(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

static void	print_config(t_config config)
{
	int	i;

	printf("Textures:\n");
	printf("  - North: %s\n", config.texture_n);
	printf("  - South: %s\n", config.texture_s);
	printf("  - East:  %s\n", config.texture_e);
	printf("  - West:  %s\n", config.texture_w);
	printf("\nColors:\n");
	printf("  - Floor:   RGB(%d, %d, %d)\n", config.floor_color.r,
			config.floor_color.g, config.floor_color.b);
	printf("  - Ceiling: RGB(%d, %d, %d)\n", config.ceiling_color.r,
			config.ceiling_color.g, config.ceiling_color.b);
	printf("\nMap Size: Width = %d, Height = %d\n", config.map_width,
			config.map_height);
	printf("\nPlayer Position:\n");
	printf("  - X: %d\n", config.player_x);
	printf("  - Y: %d\n", config.player_y);
	printf("  - Direction: %c\n", config.player_dir);
	printf("\nMap:\n");
	i = 0;
	while (config.map[i])
	{
		printf("  %s\n", config.map[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_config	config;

	if (!envp)
		error_main("env error\n");
	if (argc != 2)
		error_main("./cub3D *.cub\n");
	init_config(&config, argv[1]);
	print_config(config);
	set_window(&config);
	free_config(&config);
	return (0);
}
