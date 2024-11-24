/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:49:25 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:14:24 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	data1[];
	char	data2[];
	int		result;

	data1[] = "las nuts";
	data2[] = "las nuts llenas";
	result = ft_memcmp(data1, data2, 15);
	if (result == 0)
		write(1, "bloques iguales. \n", 20);
	else if (result < 0)
		write(1, "el primer bloque es menor que el segundo\n", 42);
	else
		write(1, "El primer bloque es mayor que el segundo. \n", 42);
	return (0);
}
*/
