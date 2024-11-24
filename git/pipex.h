/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:00:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:32:21 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/inc/libft.h"
# include <fcntl.h>    // Incluye las definiciones para operaciones de archivos
# include <stdio.h>   
	// Incluye las definiciones para operaciones de entrada/salida estándar
# include <stdlib.h>  
	// Incluye las definiciones para funciones de utilidad general
# include <sys/wait.h> // Incluye las definiciones para esperar a procesos
# include <unistd.h>

// Prototipos de funciones utilizadas en el programa

// Ejecuta un comando dado con redirección de entrada y salida
void	execute_command(int fd_in, int fd_out, char *cmd, char **env);

// Abre un archivo y devuelve su descriptor
int		open_file(char *filename, int flags, mode_t mode);

// Crea pipes y forks para ejecutar los comandos
void	create_pipes_and_forks(char **argv, char **envp, int infile_fd,
			int outfile_fd);

// Libera la memoria asignada a un array de cadenas
void	free_cmd(char **cmd);

// Obtiene el valor de la variable de entorno PATH
char	*get_env_path(char **env);

// Encuentra la ruta completa al comando usando PATH
char	*find_path(char *cmd, char **env);

// Une un directorio y un comando para crear una ruta completa
char	*join_path_and_cmd(char *path, char *cmd);

// Busca el comando en los diferentes directorios de PATH
char	*search_paths_for_cmd(char **all_paths, char *cmd);

// Maneja errores: imprime el mensaje y termina el programa
void	handle_error(const char *msg);

#endif // Termina la inclusión condicional del archivo de encabezado