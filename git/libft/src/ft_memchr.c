/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:47:16 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:14:19 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	arr[20];

	arr[20] = "testing string";
	if (ft_memchr(arr, 't', 20) != NULL)
		write(1, ft_memchr(arr, 't', 20), 5);
	// deberia imprimir un segmento de la cadena
	else
		write(1, "caracter no encontrado.\n", 24);
	return (0);
}
*/
