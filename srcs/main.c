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
#include <errno.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	cleanup(char *line)
{
	lx_token_list_free();
	free(line);
}

void	test_function(char *line)
{
	if (ft_memcmp(line, "env", 4) == 0)
		print_env();
	if (ft_memcmp(line, "export", 7) == 0)
		print_env_export();
}

__attribute__((constructor)) static void	constructor(void)
{
	const pid_t	pid = ft_getpid();

	set_proccess_id(pid);
	rl_instream = stdin;
	rl_outstream = stderr;
	using_history();
	read_history(HISTORY_FILE);
	errno = 0;
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;

	(void)argc, (void)argv;
	env_init(envp);
	while (1)
	{
		line = prompt();
		test_function(line);
		set_token_list(tokenize(line));
		cleanup(line);
		lx_debug(get_token_list());
	}
	free_all_env();
	return (0);
}
