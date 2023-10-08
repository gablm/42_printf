/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:34:06 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/05 18:24:20 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putint(int n);
int		ft_putuint(unsigned int n, char c);
int		ft_puthex(void *p);

int		ft_is_flag(int c);
int		ft_is_param(int c);

int		ft_process_flags(char *format, va_list args);
char	*find_p(char *format);
int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
char	*ft_itoa(int n);

#endif