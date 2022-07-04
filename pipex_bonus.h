/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:21:17 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/22 17:04:15 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h> 
# include <fcntl.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <sys/wait.h>

char	*cmd_execve(char **args, char **env);
char	*parsing(char **env);
void	call_parent(char **argv, char **env, int argc);
void	call_child(char **argv, char **env, int i);
void	str_error(char *str);
void	born_exec(char **envp, char **argv, int i);
void	call_father(char **argv, char **envp, int argc);

#endif