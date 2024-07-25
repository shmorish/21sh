/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:16:58 by kura              #+#    #+#             */
/*   Updated: 2024/07/26 01:09:25 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "executor.h"
#include "ft_stdio.h"
#include <stdarg.h>
#include <stdlib.h>

void	fatal_error(char *fmt, ...)
{
	va_list	ap;

	ft_dprintf(STDERR_FILENO, "fatal error: ");
	va_start(ap, fmt);
	ft_vprintf(STDERR_FILENO, fmt, &ap);
	va_end(ap);
	exit(1);
}

void	syntax_error(char *fmt, ...)
{
	va_list	ap;

	set_exit_status(EXIT_SYNTAX_ERROR);
	ft_dprintf(STDERR_FILENO, "syntax error: ");
	va_start(ap, fmt);
	ft_vprintf(STDERR_FILENO, fmt, &ap);
	va_end(ap);
}

void	*or_exit(void *ptr)
{
	if (ptr)
	{
		return (ptr);
	}
	fatal_error(ERR_MALLOC);
	return (NULL);
}
