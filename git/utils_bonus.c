/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:45:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:36:30 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// Incluye el encabezado para las definiciones necesarias

/**
** Libera la memoria asignada a un array de cadenas
** Recorre cada elemento del array,
	libera su memoria y luego libera el array en sí.
** Evita fugas de memoria al liberar todos los recursos asignados dinámicamente.
*/
void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

/**
** Encuentra la ruta completa al comando usando PATH
** Si el comando contiene un '/', verifica directamente su accesibilidad.
** Si no contiene '/',
	busca en las rutas especificadas en la variable de entorno PATH.
** @param cmd El comando a buscar
** @param env Array de variables de entorno
** @return Ruta completa al comando o NULL si no se encuentra
*/
static char	*find_path_in_env(char **env, int i)
{
	if (ft_strncmp(env[i], "PATH=", 5) == 0)
		return (env[i] + 5);
	return (NULL);
}

/**
** Obtiene el valor de la variable de entorno PATH
** Recorre las variables de entorno buscando aquella que contiene "PATH="
** Devuelve el valor de PATH o NULL si no se encuentra.
*/
char	*get_env_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	while (env[i])
	{
		path = find_path_in_env(env, i);
		if (path)
			return (path);
		i++;
	}
	return (NULL);
}

/**
** Une un directorio y un comando para crear una ruta completa
** Añade una barra al final de la ruta y concatena el comando al final.
** Devuelve la ruta completa o NULL si ocurre un error.
*/

char	*join_path_and_cmd(char *path, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full_path);
}

/**
** Verifica si se puede acceder a una ruta y tiene permisos de ejecución
** Si la ruta es válida, la devuelve; de lo contrario,
	libera su memoria y devuelve NULL.
*/

char	*check_access(char *full_path)
{
	if (full_path && access(full_path, F_OK | X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}
