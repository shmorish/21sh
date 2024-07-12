/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:50:42 by kura              #+#    #+#             */
/*   Updated: 2024/07/13 02:49:21 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_dlist.h"
#include "ft_stdlib.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

t_token	*lx_token_new(t_token_type type, char *str, size_t len)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		fatal_error(ERR_MALLOC);
	token->type = type;
	token->str = str;
	token->len = len;
	return (token);
}

void	lx_token_free(void *token)
{
	free(token);
}

void	lx_token_print(void *token)
{
	const t_token	*tok = (t_token *)token;

	printf("type: %d, str: [%.*s], len: %d\n",
		tok->type, (int)tok->len, tok->str, (int)tok->len);
}
