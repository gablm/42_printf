#include "printf.h"

int ft_printf(const char *format, ...) 
{
	va_list	args;
	int 	count;

	count = 0;
	if (!format)
		return (count);
	va_start(args, format);

	va_end(args);
	return (count);
}
