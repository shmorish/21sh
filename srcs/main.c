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

#include "env.h"
#include "executor.h"
#include "lexer.h"
#include "shell.h"
#include "test.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	g_signal;

void	cleanup(char *line)
{
	lx_token_list_free();
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;

	(void)argc, (void)argv;
	env_init(envp);
	while (1)
	{
		line = prompt();
		if (get_shell_error() == ERROR)
			continue ;
		test_function(line, envp);
		set_token_list(tokenize(line));
		lx_debug(get_token_list());
		cleanup(line);
	}
	return (0);
}
