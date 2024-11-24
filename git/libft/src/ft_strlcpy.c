/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:38:19 by armgonza          #+#    #+#             */
/*   Updated: 2023/11/03 20:05:00 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	const char	*src;
	char		dest[20];
	size_t		ret;
	char		small_dest[5];

	src = "Hello, World!";
	ret = ft_strlcpy(dest, src, sizeof(dest));
	printf("Cadena original: %s\n", src);
	printf("Cadena copiada: %s\n", dest);
	printf("Valor retornado por ft_strlcpy: %zu\n", ret);

	ret = ft_strlcpy(small_dest, src, sizeof(small_dest));
	printf("\nBuffer más pequeño:\n");
	printf("Cadena copiada: %s\n", small_dest);
	printf("Valor retornado por ft_strlcpy: %zu\n", ret);
	return (0);
}
*/