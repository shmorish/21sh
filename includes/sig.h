/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

extern int	g_signal;

void	signal_main_init(void);
void	signal_child_init(void);

void	sig_handler_heredoc(int signum, siginfo_t *info, void *ucontext);
void	sig_handler_heredoc_quit(int signum, siginfo_t *info, void *ucontext);
void	sig_handler_sigint(int signum, siginfo_t *info, void *ucontext);
void	sig_handler_sigquit(int signum, siginfo_t *info, void *ucontext);

void	check_exit(int status);

#endif