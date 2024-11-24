/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: armgonza <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/15 16:36:55 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/15 16:37:18 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char *texto1 = "putapus";
	char *texto2 = "Blyaaad";
	//llamamos a la funcon y testamos

	if (ft_strcmp(texto1, texto2) == 0)
	{
		write(1, "Las cadenas son iguales\n", 24);
	}
	else if (ft_strcmp(texto1, texto2) > 0) 
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
