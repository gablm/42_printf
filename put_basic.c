
#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putint(int n)
{
	if (n == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		return ;
	}
	ft_putchar('0' + n);
}

