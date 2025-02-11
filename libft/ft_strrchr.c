/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:28:02 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/07 15:55:13 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = (char *)s + ft_strlen(s);
	if ((char)c == '\0')
		return (result);
	while (result >= s)
	{
		if (*result == (char)c)
			return (result);
		result--;
	}
	return (NULL);
}
