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
	if (is_interactive())
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
	int		nul_fd;

	ft_dprintf(STDERR_FILENO, "\033[0m");
	if (is_interactive())
	{
		ps1 = get_env_value("PS1");
		line = readline(ps1);
		free(ps1);
	}
	else
	{
		nul_fd = open("/dev/null", O_WRONLY);
		dup2(nul_fd, STDERR_FILENO);
		line = readline(NULL);
		close(nul_fd);
	}
	if (!line)
		exit_command_line(get_exit_status());
	add_history(line);
	return (line);
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
		line = readline_with_prompt();
		test_function(line);
		set_token_list(tokenize(line));
		cleanup(line);
		lx_debug(get_token_list());
	}
	free_all_env();
	return (0);
}
