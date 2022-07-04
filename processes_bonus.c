/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:08:30 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/22 17:04:54 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	call_child(char **argv, char **env, int i)
{
	char	**args;
	char	*cmd;

	args = ft_split(argv[i], ' ');
	if (args == NULL)
		str_error("Split failed");
	cmd = cmd_execve(args, env);
	if ((execve(cmd, args, env) == -1))
		perror("Exec error");
}

void	call_parent(char **argv, char **env, int argc)
{
	char	**args;
	char	*cmd;

	args = ft_split(argv[argc - 2], ' ');
	if (args == NULL)
		str_error("Split failed");
	cmd = cmd_execve(args, env);
	if ((execve(cmd, args, env) == -1))
		perror("Exec error");
}
