/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:36:40 by armgonza          #+#    #+#             */
/*   Updated: 2024/11/11 09:25:44 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// función que lee el archivo, almacena str en el buffer y la une a la pila

static int	read_buffer(int fd, char **pila, char *buffer)
{
	char	*strtmp;
	int		bytes;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || buffer == NULL)
	{
		free(*pila);
		*pila = NULL;
		return (-1);
	}
	if (bytes == 0)
		return (bytes);
	strtmp = ft_strjoin(*pila, buffer);
	free(*pila);
	*pila = strtmp;
	return (bytes);
}

// Elimina la cadena obtenida en get_result() de la pila.

static void	remove_result(char **pila)
{
	char	*newline;
	char	*strtmp;
	size_t	i;
	size_t	j;

	newline = ft_strchr(*pila, '\n');
	if (!newline)
	{
		free(*pila);
		*pila = NULL;
		return ;
	}
	strtmp = malloc((ft_strlen(newline)) * sizeof(char));
	i = 0;
	j = ft_strlen(*pila) - ft_strlen(newline) + 1;
	while (j < ft_strlen(*pila))
		strtmp[i++] = (*pila)[j++];
	strtmp[i] = '\0';
	free(*pila);
	*pila = strtmp;
	if (**pila == 0)
	{
		free(*pila);
		*pila = NULL;
	}
}

// Toma la cadena a devolver de la pila.

static void	get_result(char **pila, char **result)
{
	char	*newline;
	size_t	len;
	size_t	i;

	newline = ft_strchr(*pila, '\n');
	len = ft_strlen(*pila) - ft_strlen(newline) + 2;
	*result = (char *)malloc(len * sizeof(char));
	if (!result)
		return ;
	i = 0;
	while (i < len - 1)
	{
		(*result)[i] = (*pila)[i];
		i++;
	}
	(*result)[i] = '\0';
}

// get_next_line()

char	*get_next_line(int fd)
{
	static char	*pila;
	char		*result;
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = 1;
	while (ft_strchr(pila, '\n') == NULL
		&& bytes > 0)
		bytes = read_buffer(fd, &pila, buffer);
	free(buffer);
	if (bytes == -1)
		return (NULL);
	if (ft_strlen(pila) == 0)
		return (NULL);
	get_result(&pila, &result);
	remove_result(&pila);
	return (result);
}
