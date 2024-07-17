/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:10:48 by tkuramot          #+#    #+#             */
/*   Updated: 2024/04/30 03:15:30 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "env.h"
#include "utils.h"

void	exit_command_line(int exit_status)
{
	if (isatty(STDIN_FILENO))
		write(STDERR_FILENO, "exit\n", 6);
	exit(exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	const pid_t	pid = ft_getpid();
	int			exit_status;
	t_env		*env;

	(void)pid;
	(void)argc;
	(void)argv;
	rl_instream = stdin;
	rl_outstream = stderr;
	exit_status = 0;
	env = env_init(envp);
	while (1)
	{
		line = readline(get_env_value(env, "PS1"));
		if (!line)
			exit_command_line(exit_status);
		add_history(line);
		free(line);
	}
	free_all_env(env);
	return (0);
}
