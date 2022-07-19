/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:08:56 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/11 17:32:17 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
#include <mlx.h>

int				ft_printf(const char *fmt, ...);
int				write_input(const char *str, va_list args);
int				write_char(char c);
int				write_string(char *str);
int				write_integer(signed long number);
int				write_unsigned_integer(unsigned int number);
int				write_hex(unsigned int number);
int				write_hex_upper(unsigned int number);
int				write_pointer(void *ptr);
int				ft_putchar(char c);
unsigned int	ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*itoa_base(unsigned long long n, char *base);

#endif