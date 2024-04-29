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

#include <readline.h>
#include <history.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	pid_t	pid;

	rl_instream = stdin;
	rl_outstream = stderr;
	pid = fork();
	if (pid == 0)
		exit(0);
	waitpid(pid, NULL, 0);
	printf("pid: %d\n", pid);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		add_history(line);
		free(line);
	}
	return (0);
}
