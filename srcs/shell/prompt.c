/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "executor.h"
#include "shell.h"
#include "libft.h"
#include "sig.h"
#include <stdlib.h>

static void	exit_command_line(int exit_status)
{
	if (is_interactive())
		write(STDERR_FILENO, "exit\n", 6);
	exit(exit_status);
}

char	*prompt(void)
{
	char	*line;

	ft_dprintf(STDERR_FILENO, "\033[0m");
	set_shell_error(NORMAL);
	save_terminal();
	signal_main_init();
	line = shell_prompt();
	if (get_shell_error() == ERROR)
		return (NULL);
	if (!line)
		exit_command_line(get_exit_status());
	return (line);
}
