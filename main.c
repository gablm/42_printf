/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:16:19 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/04 15:57:09 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* printf expectations

p -> void * aka unsigned long long
d / i -> int
u / x / X -> unsigned int // int converted to unsigned

*/ 

int	process_tag(const char *format, va_list args, int *count)
{
	int	i;

	i = 0;
	if (*format == '%')
		*count += ft_putchar('%');
	if (*format == 'c')
		*count += ft_putchar(va_arg(args, int));
	if (*format == 's')
		*count += ft_putstr(va_arg(args, char *));
	if (*format == 'd' || *format == 'i')
		*count += ft_putint(va_arg(args, int));
	if (*format == 'u' || *format == 'x' || *format == 'X')
		*count += ft_putuint(va_arg(args, unsigned int), *format);
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

#include <stdio.h>
int main(void) 
{
	int s = ft_printf("a%x\n\n%s%%", 12345, "bola");
	printf("\n======\nn1=%i\n======\n", s);
	int h = printf("a%x\n\n%s%%", 12345, "bola");
	printf("\n======\nn2=%i\n======\n", h);
	return (0);
}
