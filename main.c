/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:16:19 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/03 00:17:59 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	process_tag(const char *format, va_list args, int *count)
{
	int	i;

	i = 0;
	if (*format == 'c')
		*count += ft_putchar(va_arg(args, int));
	if (*format == 's')
		*count += ft_putstr(va_arg(args, char *));
	if (*format == 'd')
		*count += ft_putint(va_arg(args, int));
	i += 2;
	return (i);
}

int	loop_args(const char *format, va_list args)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			i++;
			count++;
			continue ;
		}
		i += process_tag(format + i + 1, args, &count);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (count);
	va_start(args, format);
	count = loop_args(format, args);
	va_end(args);
	return (count);
}

/*#include <stdio.h>
int main(void) 
{
	int s = ft_printf("a%d", 12345);
	printf("\n%d", s);
	return (0);
}
*/