/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:23:47 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/11 14:58:34 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count_lines(const char *path)
{
	int		fd;
	int		result;
	char	*line;

	result = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCan't open map\n", 2);
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		result++;
	}
	close(fd);
	return (result);
}

static void	set_result(const char *path, char ***result)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCan't open map\n", 2);
		return ;
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*result)[i++] = ft_strdup(line);
		free(line);
	}
	(*result)[i] = NULL;
	close(fd);
}

char	**read_file(const char *path)
{
	int		lines_count;
	char	**result;

	lines_count = count_lines(path);
	if (lines_count == -1)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (lines_count + 1));
	if (!result)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		return (NULL);
	}
	set_result(path, &result);
	return (result);
}
