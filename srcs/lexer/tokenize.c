/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:52 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/14 18:50:40 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_dlist.h"
#include "ft_string.h"
#include "lexer.h"
#include <stdio.h>

static bool	lx_tokenize_reserved(t_dlist **lst, const char **str)
{
	const char	*s = *str;
	if (lx_startswith(s, "<<") || lx_startswith(s, ">>")
		|| lx_startswith(s, "&&") || lx_startswith(s, "||"))
	{
		ft_dlstadd_back(lst,
			or_exit(ft_dlstnew(lx_token_new(TK_RSVD, s, 2)), ERR_MALLOC));
		*str += 2;
		return (true);
	}
	if (*s == '|' || *s == ';' || *s == '(' || *s == ')'
		|| *s == '{' || *s == '}' || *s == '<' || *s == '>')
	{
		ft_dlstadd_back(lst,
			or_exit(ft_dlstnew(lx_token_new(TK_RSVD, s, 1)), ERR_MALLOC));
		(*str)++;
		return (true);
	}
	return (false);
}

static bool	lx_tokenize_word(t_dlist **lst, const char **s)
{
	const char	*t = *s;
	char	*next_quote;
	char	quote;

	while (**s && !lx_ismetachar(**s))
	{
		if (**s == '\'' || **s == '\"')
		{
			quote = **s;
			next_quote = ft_strchr(*s + 1, quote);
			if (!next_quote)
			{
				*s = t + ft_strlen(t);
				syntax_error("unterminated quote\n");
				return (false);
			}
			*s = next_quote;
		}
		(*s)++;
	}
	ft_dlstadd_back(lst,
		or_exit(ft_dlstnew(lx_token_new(TK_WORD, t, *s - t)), ERR_MALLOC));
	return (true);
}

t_dlist	*tokenize(const char *s)
{
	t_dlist	head;
	t_dlist	*cur;

	head.next = NULL;
	cur = &head;
	while (*s)
	{
		while (lx_isspace(*s))
			s++;
		if (*s && lx_tokenize_reserved(&cur, &s))
			continue ;
		if (*s && lx_tokenize_word(&cur, &s))
			continue ;
	}
	ft_dlstadd_back(&cur,
		or_exit(ft_dlstnew(lx_token_new(TK_EOF, s, 0)), ERR_MALLOC));
	return (head.next);
}

void	lx_debug(t_dlist *lst)
{
	ft_dlstiter(lst, lx_token_print);
}
