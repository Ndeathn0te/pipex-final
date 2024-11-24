/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:54:47 by armgonza          #+#    #+#             */
/*   Updated: 2023/11/01 19:47:31 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j] && i
			+ j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		if (haystack[i + j] == '\0' || i + j == len)
			return (NULL);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*cadena_principal;
	const char	*subcadena;
	char		*resultado;

	cadena_principal = "Este es un texto de prueba";
	subcadena = "texto";
	resultado = ft_strnstr(cadena_principal, subcadena, 25);
	if (resultado)
		printf("Subcadena encontrada: %s\n", resultado);
	else
		printf("Subcadena no encontrada.\n");
	resultado = ft_strnstr(cadena_principal, subcadena, 10);
	if (resultado)
		printf("Subcadena encontrada: %s\n", resultado);
	else
		printf("Subcadena no encontrada en los primeros 10 caracteres.\n");
	return (0);
}
*/
