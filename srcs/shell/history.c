/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include <stdio.h>
#include <readline/history.h>

char	*expand_history(char *line)
{
	char	*expanded_line;
	int		ret;

	expanded_line = NULL;
	ret = history_expand(line, &expanded_line);
	if (ret == -1)
	{
		shell_error();
		ft_dprintf(STDERR_FILENO, "%s\n", expanded_line);
		free(expanded_line);
		free(line);
		expanded_line = NULL;
		line = NULL;
		set_shell_error(ERROR);
		return (NULL);
	}
	if (ret == 1)
		ft_printf("%s\n", expanded_line);
	free(line);
	return (expanded_line);
}
