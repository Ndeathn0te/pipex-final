/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:36:12 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:16:04 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == 0)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*
int	main(void)

{
	const char *string = "misbolas";
	char *result;

	result = ft_strchr(string, 's');

	if (result)
	{
		printf("se encontro la cosa??: %c\n", *result);
	}
	else
	{
		printf("Caracter no encontrado \n");
	}

	return (0);
}
*/
