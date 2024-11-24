/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:37:31 by armgonza          #+#    #+#             */
/*   Updated: 2023/11/03 23:23:03 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	if (size == 0 && dest == NULL)
		return (ft_strlen(src));
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len == size)
		return (size + src_len);
	while (src[i] && (dest_len + i + 1) < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
int	main(void)
{
	char		buffer[30];
	const char	*append;
	size_t		ret;
	char		small_buffer[10];

	ft_strlcpy(buffer, "hello, ", 4);
	append = "World!";
	ret = ft_strlcat(buffer, append, sizeof(buffer));
	printf("Cadena resultante  : %s\n", buffer);
	printf("Valor retornado por ft_strlcat: %zu\n", ret);
	ft_strlcpy(small_buffer, "Hello, ", 4);
	ret = ft_strlcat(small_buffer, append, sizeof(small_buffer));
	printf("\nBuffer mas pequeño:\n");
	printf("Cadena resultante: %s\n", small_buffer);
	printf("Valor retornado por ft_strlcat: %zu\n", ret);
	return (0);
}
*/
