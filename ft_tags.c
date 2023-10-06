/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:26:30 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/05 19:08:15 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_addzero(char c, unsigned int num)
{
	if (num != 0)
	{
		write(1, "0", 1);
		write(1, &c, 1);
		return (2 + ft_putuint(num, c));
	}
	return (ft_putuint(num, c));
}

static int	ft_addspace(char c, va_list args)
{
	int		len;
	int		num;
	char	*ans;

	len = 0;
	if (c == 's')
	{
		ans = va_arg(args, char *);
		if (!ans || ans[0] == ' ')
			len = write(1, " ", 1);
		len += ft_putstr(ans);
	}
	if (c == 'i' || c == 'd')
	{
		num = va_arg(args, int);
		if (num >= 0)
			len = write(1, " ", 1);
		len += ft_putint(num);
	}
	return (len);
}

char	*find_p(char *format)
{
	char	c;

	c = *format;
	while (*format == c)
		format++;
	return (format);
}

int	ft_process_flags(char *format, va_list args)
{
	int	c;

	if (*format == '#' && (*find_p(format) == 'x' || *find_p(format) == 'X' ))
		return (ft_addzero(*find_p(format), va_arg(args, unsigned int)));
	if (*format == ' ' && (*find_p(format) == 'd'  
		|| *find_p(format) == 'i' || *find_p(format) == 's'))
		return (ft_addspace(*find_p(format), args));
	if (*format == '+' && (*find_p(format) == 'd' 
		|| *find_p(format) == 'i'))
	{
		c = va_arg(args, int);
		if (c >= 0)
			ft_putchar('+');
		return ((c >= 0) + ft_putint(c));
	}
	return (0);
}

