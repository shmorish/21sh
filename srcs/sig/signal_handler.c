/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sig.h"
#include <stdio.h>
#include <readline/readline.h>

void	sig_handler_heredoc(int signum, siginfo_t *info, void *ucontext)
{
	(void)signum, (void)ucontext, (void)info;
	close(STDIN_FILENO);
	g_signal = 1;
}

void	sig_handler_heredoc_quit(int signum, siginfo_t *info, void *ucontext)
{
	(void)signum, (void)ucontext, (void)info;
	rl_on_new_line();
	rl_redisplay();
}

void	sig_handler_sigint(int signum, siginfo_t *info, void *ucontext)
{
	(void)signum, (void)ucontext, (void)info;
	g_signal = SIGINT;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sig_handler_sigquit(int signum, siginfo_t *info, void *ucontext)
{
	(void)signum, (void)ucontext, (void)info;
	rl_on_new_line();
	rl_redisplay();
}
