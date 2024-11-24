/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:44:17 by armgonza          #+#    #+#             */
/*   Updated: 2024/03/19 23:38:13 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_lower(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += print_hex_lower(n / 16);
	}
	len += print_char("0123456789abcdef"[n % 16]);
	return (len);
}

int	print_hex_upper(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += print_hex_upper(n / 16);
	}
	len += print_char("0123456789ABCDEF"[n % 16]);
	return (len);
}

int	print_pointer(void *ptr)
{
	int				len;
	unsigned long	address;

	len = 0;
	if (ptr == NULL)
	{
		len = print_string("0x0");
		return (len);
	}
	len += print_string("0x");
	address = (unsigned long)ptr;
	len += print_hex_lower(address);
	return (len);
}

int	print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n / 10)
	{
		len += print_unsigned(n / 10);
	}
	len += print_char((n % 10) + '0');
	return (len);
}

int	print_decimal(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		return (print_string("-2147483648"));
	}
	if (n < 0)
	{
		len += print_char('-');
		n = -n;
	}
	len += print_unsigned(n);
	return (len);
}
