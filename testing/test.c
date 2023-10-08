/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:38:55 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/08 14:38:55 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	s;
	int	h;

	(void)argc;
	(void)argv;
	s = ft_printf("% 1s", "");
	printf("\n======\nn1=%i\n======\n", s);
	h = printf("% 1s", "");
	printf("\n======\nn2=%i\n======\n", h);
	return (0);
}
