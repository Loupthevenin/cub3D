/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:38:25 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/18 14:17:22 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_read_and_join(int fd, char *buf)
{
	char	tmp[BUFFER_SIZE + 1];
	ssize_t	nb_read;

	while (!ft_strchr(buf, '\n'))
	{
		nb_read = read(fd, tmp, BUFFER_SIZE);
		if (nb_read < 0)
			return (NULL);
		if (nb_read == 0)
			break ;
		tmp[nb_read] = '\0';
		if (ft_strlen(buf) + nb_read > BUFFER_SIZE)
			return (NULL);
		ft_strlcat(buf, tmp, BUFFER_SIZE + 1);
	}
	return (buf);
}

static char	*ft_extract_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static void	ft_update_buffer(char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		buf[0] = '\0';
		return ;
	}
	i++;
	j = 0;
	while (buf[i])
		buf[j++] = buf[i++];
	buf[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_read_and_join(fd, buf))
		return (NULL);
	line = ft_extract_line(buf);
	ft_update_buffer(buf);
	return (line);
}
