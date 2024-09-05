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

#include "libft.h"
#include <stdio.h>
#include <readline/readline.h>

char	*tidle(char *line)
{
	char	*trm;
	char	*expand_rslt;

	trm = ft_strtrim(line, " \t");
	expand_rslt = tilde_expand(trm);
	free(trm);
	trm = NULL;
	free(line);
	line = NULL;
	return (expand_rslt);
}
