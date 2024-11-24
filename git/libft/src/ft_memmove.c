/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:02:41 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:14:35 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	data[30];

	data[30] = "Alo Alo Alo Alo Alo";
	ft_memmove(data + 8, data, 12);
	printf("Mover hacia adelante: %s\n", data);
	ft_memmove(data, data + 8, 12);
	printf("Mover hacia atrás:    %s\n", data);
	return (0);
}*/
