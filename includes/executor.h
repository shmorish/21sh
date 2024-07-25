/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:34:35 by kura              #+#    #+#             */
/*   Updated: 2024/07/15 01:06:59 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <unistd.h>

typedef enum e_exit_status
{
	EXIT_SYNTAX_ERROR = 2,
}		t_exit_status;

# define CURRENT_SHELL "minishell"

void	set_exit_status(int status);
int		get_exit_status(void);

void	set_proccess_id(pid_t pid);
pid_t	get_proccess_id(void);

#endif
