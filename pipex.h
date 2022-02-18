/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:21:17 by ccaswell          #+#    #+#             */
/*   Updated: 2022/02/09 13:37:36 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h> 
# include <fcntl.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <sys/wait.h>

char	*cmd_execve(char **args, char **env);
char	*parsing(char **env);
void	call_parent(int *p, char **argv, char **env);
void	call_child(int *p, char **argv, char **env);
void	str_error(char *str);

#endif