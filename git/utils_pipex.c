/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:15:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:32:21 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Función para liberar la memoria asignada a un array de strings
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

/*
===============================================
FUNCION: get_env_path
- Obtiene el valor de la variable de entorno PATH.
===============================================
ENTRADAS:
- env: Array de variables de entorno.
PROCESO:
1. Recorre las variables de entorno.
2. Compara los primeros 5 caracteres para encontrar "PATH=".
3. Si encuentra "PATH=", devuelve un puntero al valor (sin "PATH=").
SALIDA:
- Puntero al valor de PATH o NULL si no se encuentra.
*/
char	*get_env_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

/*
===============================================
FUNCION: join_path_and_cmd
- Une una ruta y un comando para formar una ruta completa.
===============================================
ENTRADAS:
- path: Ruta de un directorio.
- cmd: Comando a buscar.
PROCESO:
1. Une `path` con un separador '/'.
2. Une el resultado con `cmd`.
3. Libera la memoria temporal usada para unir.
SALIDA:
- Cadena con la ruta completa o NULL si falla.
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

/*
===============================================
FUNCION: search_paths_for_cmd
- Busca el comando en los diferentes directorios especificados en PATH.
===============================================
ENTRADAS:
- all_paths: Array con las rutas extraídas de PATH.
- cmd: Comando a buscar.
PROCESO:
1. Itera sobre cada directorio en `all_paths`.
2. Construye la ruta completa al comando.
3. Verifica si es accesible y ejecutable.
4. Libera memoria de rutas inválidas.
SALIDA:
- Ruta completa al comando o NULL si no se encuentra.
*/
// Busca el comando en los diferentes directorios especificados en PATH
char	*search_paths_for_cmd(char **all_paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (all_paths[i])
	{
		full_path = join_path_and_cmd(all_paths[i], cmd);
		if (full_path && access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

/*
===============================================
FUNCION: find_path
- Encuentra la ruta completa al comando utilizando la variable de entorno PATH.
===============================================
ENTRADAS:
- cmd: Comando a buscar.
- env: Array de variables de entorno.
PROCESO:
1. Obtiene el valor de PATH desde las variables de entorno.
2. Divide PATH en un array de rutas.
3. Busca el comando en las rutas especificadas.
4. Libera la memoria asignada a las rutas.
SALIDA:
- Ruta completa al comando o NULL si no se encuentra.
*/
char	*find_path(char *cmd, char **env)
{
	char	**all_paths;
	char	*full_path;
	char	*env_path;

	env_path = get_env_path(env);
	all_paths = ft_split(env_path, ':');
	if (!all_paths)
		return (NULL);
	full_path = search_paths_for_cmd(all_paths, cmd);
	free_cmd(all_paths);
	return (full_path);
}
