/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:52:07 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/18 14:14:05 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	m;
	int		i;
	int		len_nbr;

	m = (long int)n;
	len_nbr = count_nbr(m);
	result = (char *)malloc(sizeof(char) * (count_nbr(m) + 1));
	if (!result)
		return (NULL);
	if (m < 0)
	{
		result[0] = '-';
		m = -m;
	}
	i = len_nbr - 1;
	while (m > 9)
	{
		result[i] = (m % 10) + '0';
		m /= 10;
		i--;
	}
	result[i] = (m % 10) + '0';
	result[len_nbr] = '\0';
	return (result);
}
