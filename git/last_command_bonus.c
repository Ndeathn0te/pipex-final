/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:35:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:34:41 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
** Ejecuta el último comando en un proceso hijo
** cmd: Comando que el hijo debe ejecutar
** envp: Variables de entorno del programa
** prev_fd: Descriptor de archivo del proceso anterior,
** para leer desde el anterior comando
** outfile: Archivo de salida donde se redirige la salida del comando
*/
void	execute_last_command(char *cmd, char **envp, int prev_fd, char *outfile)
{
	int		outfile_fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		handle_error("Fork failed");
	if (pid == 0)
	{
		outfile_fd = open_file(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (outfile_fd == -1)
			handle_error("Failed to open output file");
		child_process(cmd, envp, prev_fd, outfile_fd);
	}
	close(prev_fd);
	while (wait(NULL) > 0)
		;
}
