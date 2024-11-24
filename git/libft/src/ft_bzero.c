/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:26:13 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:13:40 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr = ptr + 1;
		n--;
	}
}
/*
int	main(void)

{
	char str[] = "helloworld";

	printf("Cadena antes de ft_bzero: %s\n", str);

	ft_bzero(str, 5);
	for (size_t i = 0; i < sizeof(str); i++)
	{
		if (str[i] == '\0')
		{
			printf("\\0");
		}
		else
		{
			printf("%c", str[i]);
		}
	}
	printf("\n");

	return (0);
}
*/
