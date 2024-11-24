/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:10:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:32:21 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
** Función para ejecutar un comando dado, redireccionando la entrada y salida
** Recibe los descriptores de entrada y salida,
	el comando a ejecutar y el entorno del programa
** Redirige la entrada y salida estándar a los descriptores proporcionados
** Divide el comando en argumentos y busca su ruta en el entorno
** Si ocurre algún error (dup2, ft_split, encontrar la ruta o execve),
	lo maneja adecuadamente
** Si el comando no se encuentra,
	imprime un mensaje detallado y finaliza con error
*/
void	execute_command(int fd_in, int fd_out, char *cmd, char **env)
{
	char	**args;
	char	*path;

	if (!env || !*env)
		handle_error("Error: Environment variables missing");
	if (dup2(fd_in, STDIN_FILENO) == -1 || dup2(fd_out, STDOUT_FILENO) == -1)
		handle_error("dup2 failed");
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

void	handle_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
