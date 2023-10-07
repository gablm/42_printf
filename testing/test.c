#include "../ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv) 
{
	(void)argc;
	(void)argv;
	int s = ft_printf("%%%");
	printf("\n======\nn1=%i\n======\n", s);
	int h = printf("%%%");
	printf("\n======\nn2=%i\n======\n", h);
	return (0);
}
