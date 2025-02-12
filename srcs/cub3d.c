/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:04:05 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/11 18:50:26 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_main(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_config	config;

	if (!envp)
		error_main("env error\n");
	if (argc != 2)
		error_main("./cub3D *.cub\n");
	init_config(&config, argv[1]);
	free_config(&config);
	return (0);
}
