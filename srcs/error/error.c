/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:16:58 by kura              #+#    #+#             */
/*   Updated: 2024/07/12 20:52:59 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
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

void	*or_exit(void *ptr, char *fmt, ...)
{
	va_list	ap;

	if (ptr)
		return (ptr);
	ft_dprintf(STDERR_FILENO, "fatal error: ");
	va_start(ap, fmt);
	ft_vprintf(STDERR_FILENO, fmt, &ap);
	va_end(ap);
	exit(1);
}
