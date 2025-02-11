/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:21:06 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/11 14:22:18 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_tab(void **tabs, int size, int is_null)
{
	int	i;

	if (!tabs)
		return ;
	i = 0;
	if (is_null)
	{
		while (tabs[i])
		{
			free(tabs[i]);
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			free(tabs[i]);
			i++;
		}
	}
	free(tabs);
}
