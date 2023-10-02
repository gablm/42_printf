#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *, ...);

void	ft_putchar(char c);
void	ft_putint(int n);

#endif