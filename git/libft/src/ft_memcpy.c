/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:44:43 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:14:30 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

/*
int	main(void) {
    char src [9] = "Prueba 42";
    char dest[15];
    ft_memcpy(dest, src, 9);

    write(1, "Cadena original: ", 17);
    write(1, src, 9);
    write(1, "\n",1);

    return (0); 
}
*/
