/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:19:49 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/07 15:09:28 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*result;

	result = (const unsigned char *)s;
	while (n--)
	{
		if (*result == (unsigned char)c)
			return ((void *)result);
		result++;
	}
	return (NULL);
}
