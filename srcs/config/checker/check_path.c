/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:07:42 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/12 13:15:26 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	check_path(const char *path)
{
	int	len_path;

	len_path = ft_strlen(path);
	if (ft_strncmp(&path[len_path - 4], ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\n.cub file\n", 2);
		return (1);
	}
	return (0);
}
