/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:10:48 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/15 20:59:03 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "lexer.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <readline/history.h>
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

void	cleanup(char *line)
{
	lx_token_list_free();
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_dlist		*env;

	(void)argc, (void)argv;
	set_proccess_id(getpid());
	rl_instream = stdin;
	rl_outstream = stderr;
	env = env_init(envp);
	while (1)
	{
		ft_dprintf(STDERR_FILENO, "\033[0m");
		line = readline(get_env_value(env, "PS1"));
		if (!line)
			exit_command_line(get_exit_status());
		add_history(line);
		set_token_list(tokenize(line));
		cleanup(line);
		lx_debug(get_token_list());
	}
	free_all_env(env);
	return (0);
}
