/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: armgonza <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/15 16:40:57 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/15 16:41:09 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char *texto1 = "putapus";
	char *texto2 = "Blyaaad";

	if (ft_strncmp(texto1, texto2, 8) == 0)
	{
		write(1, "Las cadenas son iguales\n", 24);
	}
	else if (ft_strncmp(texto1, texto2, 8) > 0)
	{
		write(1, "La primera cadena es mayor que la segunda", 43);
	}

	else
	{
		write(1, "La primera cadena es menor que la segunda.\n", 43);
	}

	return (0);
}
*/
