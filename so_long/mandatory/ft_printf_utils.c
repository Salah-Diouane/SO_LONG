/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:46:21 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/23 05:46:43 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char x)
{
	return (write(1, &x, 1));
}

int	ft_putnbr(long n, int base, int type)
{
	int		cmp;
	char	*upper;
	char	*lower;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-n, base, type) + 1);
	}
	else if (n < base)
	{
		if (type == 1)
			return (ft_putchar(lower[n]));
		else
			return (ft_putchar(upper[n]));
	}
	else
	{
		cmp = ft_putnbr(n / base, base, type);
		return (cmp + ft_putnbr(n % base, base, type));
	}
}

int	ft_putstring(char *s)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	if (!s)
	{
		cmp += write(1, "(null)", 6);
		if (cmp < 0)
			return (-1);
		return (cmp);
	}
	while (s[i])
	{
		cmp += write(1, &s[i], 1);
		if (cmp < 0)
			return (-1);
		i++;
	}
	return (cmp);
}
