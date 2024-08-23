/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <string.h>

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

void	error_with_function(char *func_name)
{
	shell_error();
	ft_dprintf(STDERR_FILENO, "%s: ", func_name);
	ft_dprintf(STDERR_FILENO, "%s\n", strerror(errno));
}
