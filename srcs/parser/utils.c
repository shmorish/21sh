/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:02:39 by kura              #+#    #+#             */
/*   Updated: 2024/07/26 02:38:16 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "lexer.h"

bool	consume_reserved(char *r)
{
	const t_dlist	*lst = get_token_list();
	t_token			*token;

	if (!lst)
		return (false);
	token = lst->content;
	if (token->type != TK_RSVD)
		return (false);
	if (ft_memcmp(token->str, r, ft_strlen(r) + 1))
		return (false);
	set_token_list(lst->next);
	return (true);
}

bool	consume_type(t_token_type t)
{
	const t_dlist	*lst = get_token_list();
	t_token			*token;

	if (!lst)
		return (false);
	token = lst->content;
	if (token->type != t)
		return (false);
	set_token_list(lst->next);
	return (true);
}

bool	expect_reserved(char *r)
{
	const t_dlist	*lst = get_token_list();
	t_token			*token;

	if (!lst)
		return (false);
	token = lst->content;
	if (token->type != TK_RSVD)
		return (false);
	if (ft_memcmp(token->str, r, ft_strlen(r) + 1))
		return (false);
	set_token_list(lst->next);
	return (true);
}

bool	expect_type(t_token_type t)
{
	const t_dlist	*lst = get_token_list();
	t_token			*token;

	if (!lst)
		return (false);
	token = lst->content;
	if (token->type != t)
		return (false);
	set_token_list(lst->next);
	return (true);
}
