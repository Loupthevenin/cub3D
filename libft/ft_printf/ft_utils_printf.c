/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:04:14 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/18 14:48:22 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_putchar(char const c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned long n, int is_upper)
{
	char	*base;
	char	c;
	int		count;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, is_upper);
	c = base[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putptr(void *p)
{
	int	count;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	count += ft_puthex((unsigned long)p, 0);
	return (count);
}
