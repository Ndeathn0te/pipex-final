/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:35:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:42:09 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
** Encuentra la ruta completa al comando usando PATH
** Si el comando contiene un '/', verifica directamente su accesibilidad.
** Si no contiene '/',
	busca en las rutas especificadas en la variable de entorno PATH.
** @param cmd El comando a buscar
** @param env Array de variables de entorno
** @return Ruta completa al comando o NULL si no se encuentra
*/
char	*find_path(char *cmd, char **env)
{
	char	**all_paths;
	char	*full_path;
	char	*env_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	env_path = get_env_path(env);
	if (!env_path)
		return (NULL);
	all_paths = ft_split(env_path, ':');
	if (!all_paths)
		return (NULL);
	full_path = search_paths_for_cmd(all_paths, cmd);
	free_cmd(all_paths);
	return (full_path);
}

/**
** Espera al último proceso hijo y a todos los demás
** last_pid: PID del último proceso hijo que debe ser esperado
** status: Variable que almacena el estado de salida del proceso hijo
*/
void	parent_process(int last_pid)
{
	int	status;

	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0)
		;
}

/**
** Crea una tubería y un proceso hijo para ejecutar un comando intermedio
** cmd: Comando que el hijo debe ejecutar
** envp: Variables de entorno del programa
** prev_fd: Descriptor de archivo del proceso anterior,
	para leer desde el anterior comando
** pipe_fd: Descriptores de archivo de la tubería,
	usados para pasar datos entre procesos
*/
void	create_pipe_and_fork(char *cmd, char **envp, int *prev_fd, int *pipe_fd)
{
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		handle_error("Pipe failed");
	pid = fork();
	if (pid == -1)
		handle_error("Fork failed");
	if (pid == 0)
	{
		close(pipe_fd[0]);
		child_process(cmd, envp, *prev_fd, pipe_fd[1]);
	}
	close(pipe_fd[1]);
	close(*prev_fd);
	*prev_fd = pipe_fd[0];
}

/**
** Ejecuta los comandos proporcionados en los argumentos
** argc: Número de argumentos pasados al programa
** argv: Array de argumentos, donde argv[1] es el archivo de entrada y argv[argc
	- 1] el archivo de salida
** envp: Variables de entorno del programa
*/
void	execute_commands(int argc, char **argv, char **envp)
{
	int		i;
	int		pipe_fd[2];
	int		prev_fd;

	prev_fd = open_file(argv[1], O_RDONLY, 0);
	if (prev_fd == -1)
		handle_error("Failed to open input file");
	i = 2;
	while (i < argc - 2)
	{
		create_pipe_and_fork(argv[i], envp, &prev_fd, pipe_fd);
		i++;
	}
	execute_last_command(argv[i], envp, prev_fd, argv[argc - 1]);
}

/**
** **envp recibe el entorno del programa
** Verifica que envp no sea NULL
**Verifica que se hayan proporcionado suficientes argumentos
** si es que no Imprime el uso correcto del programa
** Ejecuta los comandos
** Finaliza el programa exitosamente
*/
int	main(int argc, char **argv, char **envp)
{
	if (!envp || !*envp)
	{
		ft_putstr_fd("Error: Environment variables missing\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 ... cmdN outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	execute_commands(argc, argv, envp);
	return (0);
}
