/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:05:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:32:21 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" // Incluye el archivo de cabecera personalizado "pipex.h"

/* Función para abrir un archivo y devolver su descriptor */
int	open_file(char *filename, int flags, mode_t mode)
{
	int	fd;

	fd = open(filename, flags, mode);
	if (fd < 0)
		handle_error("Error opening file");
	return (fd);
}

/**
** Función que configura el primer proceso hijo para ejecutar el comando
** Verifica si el proceso es el hijo (pid == 0)
** Redirige la entrada estándar del proceso hijo al archivo de entrada
** Redirige la salida estándar del proceso hijo a la tubería de escritura
** Cierra los descriptores de la tubería y los archivos ya que se redirigen
** Ejecuta el comando correspondiente en el proceso hijo
*/
static void	setup_child_process(int infile_fd, int pipe_fd[], char **argv,
		char **envp)
{
	if (dup2(infile_fd, STDIN_FILENO) == -1 || dup2(pipe_fd[1],
			STDOUT_FILENO) == -1)
		handle_error("dup2 failed");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile_fd);
	execute_command(STDIN_FILENO, STDOUT_FILENO, argv[2], envp);
}

/**
** Función que configura el segundo proceso hijo para ejecutar el comando
** Verifica si el proceso es el hijo (pid2 == 0)
** Redirige la entrada estándar del proceso hijo a la tubería de lectura
** Redirige la salida estándar del proceso hijo al archivo de salida
** Cierra los descriptores de la tubería y los archivos ya que se redirigen
** Ejecuta el comando correspondiente en el proceso hijo
*/
static void	setup_second_child(int pipe_fd[], int outfile_fd, char **argv,
		char **envp)
{
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1 || dup2(outfile_fd,
			STDOUT_FILENO) == -1)
		handle_error("dup2 failed");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(outfile_fd);
	execute_command(STDIN_FILENO, STDOUT_FILENO, argv[3], envp);
}

/**
** Función que crea una tubería y dos procesos hijos para ejecutar los comandos
** Crea una tubería para comunicar los procesos
** Crea el primer proceso hijo (pid1) para ejecutar el primer comando
** Configura el primer proceso hijo y redirige los archivos y la tubería
** Crea el segundo proceso hijo (pid2) para ejecutar el segundo comando
** Configura el segundo proceso hijo y redirige los archivos y la tubería
** Cierra los descriptores de los archivos y las tuberías
** Espera a que los procesos hijos finalicen
*/
void	create_pipes_and_forks(char **argv, char **envp, int infile_fd,
		int outfile_fd)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipe_fd) == -1)
		handle_error("Pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		handle_error("Fork failed");
	if (pid1 == 0)
		setup_child_process(infile_fd, pipe_fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		handle_error("Fork failed");
	if (pid2 == 0)
		setup_second_child(pipe_fd, outfile_fd, argv, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile_fd);
	close(outfile_fd);
	while (wait(NULL) > 0)
		;
}

/**
** Función principal del programa
** Verifica que envp no sea NULL
** Verifica que se haya pasado la cantidad correcta de argumentos
** Si no es así, imprime el uso correcto del programa y termina con un error
** Abre el archivo de entrada y el archivo de salida
** Crea las tuberías y los procesos hijos para ejecutar los comandos
** Cierra los descriptores de archivo y termina el programa exitosamente
*/
int	main(int argc, char **argv, char **envp)
{
	int	infile_fd;
	int	outfile_fd;

	if (!envp || !*envp)
	{
		ft_putstr_fd("Error: Environment variables missing\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	infile_fd = open_file(argv[1], O_RDONLY, 0);
	outfile_fd = open_file(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	create_pipes_and_forks(argv, envp, infile_fd, outfile_fd);
	close(infile_fd);
	close(outfile_fd);
	return (0);
}
