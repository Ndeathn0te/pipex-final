/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:44:11 by armgonza          #+#    #+#             */
/*   Updated: 2024/03/19 23:25:14 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(args, int));
	else if (specifier == 's')
		count = print_string(va_arg(args, char *));
	else if (specifier == 'p')
		count = print_pointer(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count = print_decimal(va_arg(args, int));
	else if (specifier == 'u')
		count = print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count = print_hex_lower(va_arg(args, unsigned int));
	else if (specifier == 'X')
		count = print_hex_upper(va_arg(args, unsigned int));
	else if (specifier == '%')
		count = print_percent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		length;

	length = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			length += check_format(format[++i], args);
			i += (format[i] != '\0');
		}
		else
		{
			length += print_char(format[i++]);
		}
	}
	va_end(args);
	return (length);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_string(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		return (print_string("(null)"));
	}
	while (s[len])
	{
		print_char(s[len]);
		len++;
	}
	return (len);
}

int	print_percent(void)
{
	return (print_char('%'));
}

/*
int	main(void) {
		// Prueba con caracteres
		ft_printf("Carácter: %c\n", 'A');
		printf("Caracter: %c\n", 'A');

		// Prueba con cadenas
		ft_printf("Cadena: %s\n", "Hola, mundo!");
		printf("Cadena: %s\n", "Hola, mundo!");

		// Prueba con punteros
		int x = 10;
		ft_printf("Puntero: %p\n", &x);
		printf("puntero: %p\n", &x);

		// Prueba con enteros y decimales
		ft_printf("Entero: %d\n", -42);
		printf("Entero: %d\n", -42);
		ft_printf("Decimal: %i\n", 2024);
		printf("Decimal %i\n", 2024);

		// Prueba con enteros sin signo
		ft_printf("Entero sin signo: %u\n", 42);

		// Prueba con hexadecimal en minúsculas y mayúsculas
		ft_printf("Hexadecimal (minúsculas): %x\n", 255);
		ft_printf("Hexadecimal (mayúsculas): %X\n", 255);

		// Prueba con el símbolo de porcentaje
		ft_printf("Porcentaje: %%\n");

		return (0);
}
*/
