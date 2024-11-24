/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:00 by usuario           #+#    #+#             */
/*   Updated: 2024/11/24 18:32:21 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
// Comienza la inclusión condicional del archivo de encabezado
# define PIPEX_BONUS_H // Define PIPEX_BONUS_H para evitar inclusiones múltiples

# include "libft/inc/libft.h" // Incluye la biblioteca personalizada libft
# include <fcntl.h>
// Incluye las definiciones para operaciones de archivos
# include <stdio.h>
// Incluye las definiciones para operaciones de entrada/salida estándar
# include <stdlib.h>
// Incluye las definiciones para funciones de utilidad general
# include <sys/wait.h>
// Incluye las definiciones para esperar a procesos
# include <unistd.h>
// Incluye las definiciones para operaciones del sistema POSIX

// Ejecuta un comando dado con el entorno proporcionado
void	execute_command(char *cmd, char **env);

// Abre un archivo y devuelve su descriptor
int		open_file(char *filename, int flags, mode_t mode);

// Ejecuta un comando en un proceso hijo con redirección de entrada y salida
void	child_process(char *cmd, char **env, int input_fd, int output_fd);

// Ejecuta el último comando en un proceso hijo
void	execute_last_command(char *cmd, char **envp, int prev_fd,
			char *outfile);

// Espera al último proceso hijo y a todos los demás
void	parent_process(int last_pid);

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

// Verifica si se puede acceder a una ruta y tiene permisos de ejecución
char	*check_access(char *full_path);

// Maneja errores: imprime el mensaje y termina el programa
void	handle_error(const char *msg);

#endif // Termina la inclusión condicional del archivo de encabezado