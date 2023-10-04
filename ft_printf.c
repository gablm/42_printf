/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:37:03 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/04 18:37:03 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* printf expectations
p -> void * aka unsigned long long
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
	if (*format == 'p')
		*count += ft_puthex(va_arg(args, void *));
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
