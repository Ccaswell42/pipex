/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:05:06 by ccaswell          #+#    #+#             */
/*   Updated: 2022/02/08 16:59:57 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	str_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

int	main(int argc, char *argv[], char *env[])
{
	int		p[2];
	pid_t	pid;

	if ((argc != 5))
		str_error("Wrong number of arguments");
	if (pipe(p) < 0)
		perror("Pipe error");
	pid = fork();
	if (pid < 0)
		perror("Fork failed");
	if (pid == 0)
		call_child(p, argv, env);
	else
		call_parent(p, argv, env);
	return (0);
}
