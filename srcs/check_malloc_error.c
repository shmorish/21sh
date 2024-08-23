/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include <stdlib.h>

void	*check_malloc_error(void *ret)
{
	if (ret == NULL)
	{
		shell_error();
		ft_dprintf(STDERR_FILENO, "out of virtual memory\n");
		exit(2);
	}
	return (ret);
}
