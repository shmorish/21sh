/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft.h"
#include "sig.h"

static void	test_other_command(char *command, char **envp)
{
	pid_t		pid;
	char const	*argv[] = {command, NULL};
	int			status;

	pid = fork();
	if (pid == 0)
	{
		signal_child_init();
		execve(argv[0], (char *const *)argv, envp);
		perror("execve");
		exit(1);
	}
	waitpid(pid, &status, 0);
	check_exit(status);
}

void	test_function(char *line, char **envp)
{
	if (ft_memcmp(line, "env", 4) == 0)
		print_env();
	if (ft_memcmp(line, "export", 7) == 0)
		print_env_export();
	if (ft_memcmp(line, "top", 4) == 0)
		test_other_command("/usr/bin/top", envp);
}
