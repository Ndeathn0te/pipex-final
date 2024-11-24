/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:23:24 by armgonza          #+#    #+#             */
/*   Updated: 2024/03/19 23:23:24 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_string(char *s);
int	print_pointer(void *ptr);
int	print_decimal(int n);
int	print_unsigned(unsigned int n);
int	print_hex_upper(unsigned long n);
int	print_hex_lower(unsigned long n);
int	print_percent(void);

#endif
