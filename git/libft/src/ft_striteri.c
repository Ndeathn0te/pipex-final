/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:07:28 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:19:15 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	replace_char(unsigned int index, char *c)
{
	if (index == 2 || index == 5)
		*c = '#';
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char str[] = "abcdefghijklmnopqrpqrstuvwxyz"; // Nuestra cadena de prueba
	printf("Original: %s\n", str);               
		// Imprimimos la cadena original
	ft_striteri(str, replace_char);
	printf("Modified: %s\n", str); // modificado
	return (0);                    // Corregido el return
}
*/
