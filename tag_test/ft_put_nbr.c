/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:42:29 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/04 15:58:17 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int n)
{
	int		res;
	char	*str;

	str = ft_itoa(n);
	res = ft_strlen(str);
	write(1, str, res);
	free(str);
	return (res);
}

int	ft_putuint(unsigned int n, char c)
{
	int				res;
	unsigned int	nbase;
	char			*base;

	nbase = 10;
	if (c == 'X' || c == 'x')
		nbase = 16;
	res = 0;
	if (n > nbase - 1)
	{
		res += ft_putuint(n / nbase, c);
		res += ft_putuint(n % nbase, c);
		return (res);
	}
	base = "0123456789";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'x')
		base = "0123456789abcdef";
	ft_putchar(base[n]);
	return (1);
}

int	ft_puthex(void *p)
{
	int				i;
	int				num;
	unsigned long	pointer;
	int				written;

	written = 0;
	pointer = (unsigned long)p;
	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = (sizeof(pointer) << 3) - 4;
	while (i >= 0)
	{
		num = (pointer >> i) & 0xf;
		if (num != 0 || written > 0)
		{
			ft_putchar("0123456789abcdef"[num]);
			written++;
		}
		i -= 4;
	}
	return (written + 2);
}
