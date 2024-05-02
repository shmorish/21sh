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

pid_t	get_own_pid(void)
{
	pid_t	pid;
	pid_t	ownpid;

	pid = fork();
	ownpid = pid - 1;
	if (pid == 0)
		exit(0);
	waitpid(pid, NULL, 0);
	return (ownpid);
}

void	exit_command_line(int exit_status)
{
	if (isatty(STDIN_FILENO))
		write(STDERR_FILENO, "exit\n", 6);
	exit(exit_status);
}

int	main(void)
{
	char		*line;
	const pid_t	pid = get_own_pid();
	int			exit_status;

	(void)pid;
	rl_instream = stdin;
	rl_outstream = stderr;
	exit_status = 0;
	while (1)
	{
		line = readline("> ");
		if (!line)
			exit_command_line(exit_status);
		add_history(line);
		free(line);
	}
	return (0);
}
