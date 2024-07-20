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

int	main(void)
{
	char		*line;
	const pid_t	pid = ft_getpid();

	(void)pid;
	rl_instream = stdin;
	rl_outstream = stderr;
	while (1)
	{
		line = readline("> ");
		if (!line)
			exit_command_line(get_exit_status());
		add_history(line);
		set_token_list(tokenize(line));
		if (get_exit_status() != 0)
		{
			cleanup(line);
			continue ;
		}
		lx_debug(get_token_list());
	}
	return (0);
}
