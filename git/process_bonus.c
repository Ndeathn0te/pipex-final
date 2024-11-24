/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:40:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:32:21 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// Incluye el encabezado personalizado para las definiciones necesarias

/**
** Función para abrir un archivo y devolver su descriptor
** Recibe el nombre del archivo, los flags de apertura y el modo de creación
** Si ocurre un error al abrir el archivo, maneja el error
** Devuelve el descriptor de archivo correspondiente
*/
int	open_file(char *filename, int flags, mode_t mode)
{
	int	fd;

	fd = open(filename, flags, mode);
	if (fd < 0)
		handle_error("Error opening file");
	return (fd);
}

/**
** Función para ejecutar un comando
** Recibe un comando y el entorno del programa
** Verifica si env es válido
** Divide el comando en argumentos y busca su ruta en el entorno
** Si el comando no se encuentra, maneja el error e imprime un mensaje
** Ejecuta el comando usando execve
*/
void	execute_command(char *cmd, char **env)
{
	char	**args;
	char	*path;

	if (!env || !*env)
		handle_error("Error: Environment variables missing");
	args = ft_split(cmd, ' ');
	if (!args)
		handle_error("ft_split failed");
	path = find_path(args[0], env);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(args[0], 2);
		free_cmd(args);
		handle_error("Command not found");
	}
	execve(path, args, env);
	handle_error("execve failed");
}

/**
** Función que ejecuta un comando en un proceso hijo
** Recibe el comando, el entorno, y los descriptores de entrada y salida
** Redirige la entrada y salida estándar a los descriptores proporcionados
** Divide el comando en argumentos, busca su ruta y lo ejecuta
** Si ocurre algún error, maneja el error
*/
void	child_process(char *cmd, char **env, int input_fd, int output_fd)
{
	char	**args;
	char	*path;

	if (dup2(input_fd, STDIN_FILENO) == -1 || dup2(output_fd,
			STDOUT_FILENO) == -1)
		handle_error("dup2 failed");
	close(input_fd);
	close(output_fd);
	if (!env || !*env)
		handle_error("Error: Environment variables missing");
	args = ft_split(cmd, ' ');
	if (!args)
		handle_error("ft_split failed");
	path = find_path(args[0], env);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(args[0], 2);
		free_cmd(args);
		handle_error("Command not found");
	}
	execve(path, args, env);
	handle_error("execve failed");
}

/*cierra el programa y maneja el mensaje de error */
void	handle_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/**
** Busca el comando en los diferentes directorios de PATH
** Recorre las rutas de PATH,
	crea una ruta completa para el comando y verifica su accesibilidad.
** Devuelve la ruta completa si el comando se encuentra o NULL si no existe.
*/

/**
** Busca la ruta completa del comando en todas las rutas especificadas
** Usa check_access para validar la ruta completa.
** @param all_paths Array de rutas
** @param cmd El comando a buscar
** @return Ruta completa al comando o NULL si no se encuentra
*/
char	*search_paths_for_cmd(char **all_paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (all_paths[i])
	{
		full_path = join_path_and_cmd(all_paths[i], cmd);
		full_path = check_access(full_path);
		if (full_path)
			return (full_path);
		i++;
	}
	return (NULL);
}
