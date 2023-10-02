/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:15:31 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/03 00:16:12 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, str + i++, 1);
	return (i);
}

int	ft_putint(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
	{
		ft_putint(-2);
		ft_putint(147483648);
		return (11);
	}
	if (n < 0)
	{
		res += ft_putchar('-');
		res += ft_putint(-n);
		return (res);
	}
	if (n > 9)
	{
		res += ft_putint(n / 10);
		res += ft_putint(n % 10);
		return (res);
	}
	ft_putchar('0' + n);
	return (1);
}
