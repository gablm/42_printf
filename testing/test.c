#include "../ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv) 
{
	(void)argc;
	int s = ft_printf("%p", argv);
	printf("\n======\nn1=%i\n======\n", s);
	int h = printf("%p", argv);
	printf("\n======\nn2=%i\n======\n", h);
	return (0);
}
