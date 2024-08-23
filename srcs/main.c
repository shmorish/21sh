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
#include <stdio.h>
#include <readline/readline.h>

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
		line = prompt();
		test_function(line);
		set_token_list(tokenize(line));
		lx_debug(get_token_list());
		cleanup(line);
	}
	free_all_env();
	return (0);
}
