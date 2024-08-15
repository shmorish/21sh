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

char	*readline_with_prompt(void)
{
	char	*line;
	char	*ps1;

	ps1 = get_env_value("PS1");
	line = readline(ps1);
	free(ps1);
	if (!line)
		exit_command_line(get_exit_status());
	add_history(line);
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;

	(void)argc, (void)argv;
	set_proccess_id(ft_getpid());
	rl_instream = stdin;
	rl_outstream = stderr;
	env_init(envp);
	while (1)
	{
		ft_dprintf(STDERR_FILENO, "\033[0m");
		line = readline_with_prompt();
		set_token_list(tokenize(line));
		cleanup(line);
		lx_debug(get_token_list());
	}
	free_all_env();
	return (0);
}
