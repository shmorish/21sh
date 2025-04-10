/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "sig.h"
#include <signal.h>

void	signal_main_init(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	if (g_signal == 1 || g_signal == SIGINT)
		set_exit_status(130);
	sigemptyset(&act1.sa_mask);
	act1.sa_sigaction = sig_handler_sigint;
	act1.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act1, NULL);
	sigemptyset(&act2.sa_mask);
	act2.sa_sigaction = sig_handler_sigquit;
	act2.sa_flags = SA_SIGINFO;
	sigaction(SIGQUIT, &act2, NULL);
}

void	signal_child_init(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	sigemptyset(&act1.sa_mask);
	act1.sa_handler = SIG_DFL;
	act1.sa_flags = 0;
	sigaction(SIGINT, &act1, NULL);
	sigemptyset(&act2.sa_mask);
	act2.sa_handler = SIG_DFL;
	act2.sa_flags = 0;
	sigaction(SIGQUIT, &act2, NULL);
}

void	signal_parent_init(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	sigemptyset(&act1.sa_mask);
	act1.sa_handler = SIG_IGN;
	act1.sa_flags = 0;
	sigaction(SIGINT, &act1, NULL);
	sigemptyset(&act2.sa_mask);
	act2.sa_handler = SIG_IGN;
	act2.sa_flags = 0;
	sigaction(SIGQUIT, &act2, NULL);
}

void	signal_heredoc(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	sigemptyset(&act1.sa_mask);
	act1.sa_sigaction = sig_handler_heredoc;
	act1.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act1, NULL);
	sigemptyset(&act2.sa_mask);
	act2.sa_sigaction = sig_handler_heredoc_quit;
	act2.sa_flags = SA_SIGINFO;
	sigaction(SIGQUIT, &act2, NULL);
}
