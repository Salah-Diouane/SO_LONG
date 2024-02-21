/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:45:33 by sdiouane          #+#    #+#             */
/*   Updated: 2024/01/23 06:31:16 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_format(char c, va_list lst, int cmp)
{
	if (c == 'c')
		cmp = ft_putchar(va_arg(lst, int));
	else if (c == 's')
		cmp = ft_putstring(va_arg(lst, char *));
	else if (c == 'd')
		cmp = ft_putnbr(va_arg(lst, int), 10, 1);
	else if (c == '%')
		cmp = write(1, "%", 1);
	else
		write(1, &c, 1);
	return (cmp);
}

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		i;
	int		cmp;

	va_start(lst, s);
	cmp = 0;
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			cmp += ft_format(s[++i], lst, cmp);
		}
		else if (s[i] != '%')
			cmp += ft_putchar(s[i]);
		i++;
	}
	va_end(lst);
	return (cmp);
}
