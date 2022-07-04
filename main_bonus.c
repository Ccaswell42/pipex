/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:05:06 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/23 12:18:47 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	str_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

void	born_exec(char **envp, char **argv, int i)
{
	int		files[2];
	pid_t	pid;

	if (pipe(files) < 0)
		perror("Pipe error");
	pid = fork();
	if (pid < 0)
		perror("Fork failed");
	if (pid == 0)
	{	
		close(files[0]);
		dup2(files[1], 1);
		call_child(argv, envp, i);
	}
	else
	{
		close(files[1]);
		dup2(files[0], 0);
	}
}

void	call_father(char **argv, char **envp, int argc)
{
	int		out;
	pid_t	waitall;

	out = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (out < 0)
	{
		perror("Open failed");
		exit (1);
	}
	dup2(out, 1);
	waitall = fork();
	if (!waitall)
		call_parent(argv, envp, argc);
	else
		waitpid(waitall, NULL, 0);
}

int	main(int argc, char *argv[], char *env[])
{
	int		i;
	int		inp;

	i = 2;
	inp = open(argv[1], O_RDWR);
	if (inp < 0)
	{
		perror("Open failed");
		exit (1);
	}
	dup2(inp, 0);
	if ((argc < 5))
		str_error("Wrong number of arguments");
	while (i < argc - 2)
	{
		born_exec(env, argv, i);
		i++;
	}
	call_father(argv, env, argc);
	return (0);
}
