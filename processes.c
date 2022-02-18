/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:08:30 by ccaswell          #+#    #+#             */
/*   Updated: 2022/02/09 12:45:04 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	call_child(int *p, char **argv, char **env)
{
	int		inp;
	char	**args;
	char	*cmd;

	close(p[0]);
	dup2(p[1], 1);
	inp = open(argv[1], O_RDWR);
	if (inp < 0)
	{
		perror("Open failed");
		exit (1);
	}
	args = ft_split(argv[2], ' ');
	if (args == NULL)
		str_error("Split failed");
	cmd = cmd_execve(args, env);
	dup2(inp, 0);
	close(inp);
	if ((execve(cmd, args, env) == -1))
		perror("Exec error");
}

void	call_parent(int *p, char **argv, char **env)
{
	int		out;
	char	**args;
	char	*cmd;

	wait(0);
	out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (out < 0)
	{
		perror("Open failed");
		exit (1);
	}
	close(p[1]);
	dup2(p[0], 0);
	args = ft_split(argv[3], ' ');
	if (args == NULL)
		str_error("Split failed");
	cmd = cmd_execve(args, env);
	dup2(out, 1);
	close(out);
	if ((execve(cmd, args, env) == -1))
		perror("Exec error");
}
