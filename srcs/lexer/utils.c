/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:41:04 by kura              #+#    #+#             */
/*   Updated: 2024/07/14 20:57:20 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "lexer.h"
#include <stdbool.h>

// look for man bash "DEFINITIONS"
bool	lx_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

// look for man bash "DEFINITIONS"
bool	lx_ismetachar(char c)
{
	return (ft_strchr("`|;()<> \t", c) != NULL);
}

bool	lx_startswith(const char *s, char *prefix)
{
	return (ft_strncmp(s, prefix, ft_strlen(prefix)) == 0);
}
