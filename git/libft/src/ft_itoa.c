/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:47:26 by armgonza          #+#    #+#             */
/*   Updated: 2023/11/03 04:05:44 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_numlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, int n)
{
	int	is_negative;

	is_negative = (n < 0);
	while (n != 0)
	{
		*str = ft_abs(n % 10) + '0';
		n = n / 10;
		str--;
	}
	if (is_negative)
		*str = '-';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
		fill_str(str + len - 1, n);
	return (str);
}
/*
int main(void)
{
    char *result;

    result = ft_itoa(1234567);

    // Imprimir el resultado
    if (result) {
        printf("El resultado de ft_itoa es: %s\n", result);
        free(result); // Liberar la memoria asignada por ft_itoa
    } else {
        printf("ft_itoa ha devuelto NULL.\n");
    }

    return 0;
}
*/