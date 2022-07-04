/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:18:16 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/22 15:56:07 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*parsing(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

char	*cmd_execve(char **args, char **env)
{
	int		i;
	char	*cmd;
	char	**mypaths;
	char	*path;

	path = parsing(env);
	mypaths = ft_split(path, ':');
	if (mypaths == NULL)
		str_error("Split failed");
	i = -1;
	while (mypaths[++i])
	{
		cmd = ft_strjoin(mypaths[i], "/");
		cmd = ft_strjoin(cmd, args[0]);
		if (access(cmd, 1) == 0)
			break ;
	}
	if (access(cmd, 1) != 0)
	{
		free(cmd);
		perror("Access error");
		exit (1);
	}
	return (cmd);
}
