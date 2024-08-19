/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c　　　　                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

#ifdef SHELL

void	shell_error(void)
{
	ft_dprintf(STDERR_FILENO, "bash: ");
}

#else

void	shell_error(void)
{
	ft_dprintf(STDERR_FILENO, "minishell: ");
}

#endif

bool	is_interactive(void)
{
	return (isatty(STDIN_FILENO) \
			&& isatty(STDOUT_FILENO) \
			&& isatty(STDERR_FILENO));
}
