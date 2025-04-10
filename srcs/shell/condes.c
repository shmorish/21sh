/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:10:48 by shmorish          #+#    #+#             */
/*   Updated: 2024/07/15 20:59:03 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "executor.h"
#include "shell.h"
#include <errno.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
extern int	g_signal;

__attribute__((constructor)) static void	constructor(void)
{
	set_proccess_id(ft_getpid());
	set_exit_status(0);
	rl_instream = stdin;
	rl_outstream = stderr;
	using_history();
	if (is_interactive())
		read_history(HISTORY_FILE);
	errno = 0;
	g_signal = 0;
}

__attribute__((destructor)) static void	destructor(void)
{
	free_all_env();
	write_history(HISTORY_FILE);
	clear_history();
}
