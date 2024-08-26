/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdbool.h>

# define NORMAL 0
# define ERROR 1
# define HISTORY_FILE ".minishell_history"

// error_msg.c
void	shell_error(void);
void	error_from_function(char *func_name);
void	error_msg(char *func_name);

// history.c
char	*expand_history(char *line);

// prompt.c
char	*prompt(void);

// shell_expand_error.c
void	set_shell_error(int status);
int		get_shell_error(void);

// shell_prompt.c
char	*shell_prompt(void);

// tilde.c
char	*tidle(char *line);

// utils.c
bool	is_interactive(void);

#endif