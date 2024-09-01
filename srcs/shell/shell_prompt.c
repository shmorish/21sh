/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_interactive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "shell.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>

static char	*interactive_prompt(void)
{
	char	*line;
	char	*ps1;

	ps1 = get_env_value("PS1");
	line = readline(ps1);
	free(ps1);
	if (!line)
		return (NULL);
	return (line);
}

static char	*non_interactive_prompt(void)
{
	char	*line;
	int		nul_fd;

	nul_fd = open("/dev/null", O_WRONLY);
	if (nul_fd < 0)
		return (readline(NULL));
	dup2(nul_fd, STDERR_FILENO);
	line = readline(NULL);
	close(nul_fd);
	return (line);
}

static void	history_append(char *line)
{
	if (is_interactive())
	{
		if (ft_strlen(line) != 0)
			add_history(line);
	}
}

char	*shell_prompt(void)
{
	char	*line;
	char	*expand_rslt;

	if (is_interactive())
		line = interactive_prompt();
	else
		line = non_interactive_prompt();
	if (!line)
		return (NULL);
	line = expand_history(line);
	if (!line)
		return (NULL);
	if (is_interactive())
		history_append(line);
	expand_rslt = tidle(line);
	return (expand_rslt);
}
