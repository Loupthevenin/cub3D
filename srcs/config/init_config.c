/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:10:59 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/11 14:58:51 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_config(t_config *config, const char *path)
{
	char	**file_content;
	int		i;

	(void)config;
	file_content = read_file(path);
	if (!file_content)
		exit(EXIT_FAILURE);
	i = 0;
	while (file_content[i])
	{
		printf("%s", file_content[i++]);
	}
	free_tab((void **)file_content, 0, 1);
}
