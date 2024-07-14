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

typedef enum e_exit_status
{
	EXIT_SYNTAX_ERROR = 2,
}		t_exit_status;

void	set_exit_status(int status);
int		get_exit_status(void);

#endif
