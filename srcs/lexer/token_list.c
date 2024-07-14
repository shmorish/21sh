/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:26:11 by kura              #+#    #+#             */
/*   Updated: 2024/07/15 01:26:54 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stdbool.h>

static t_dlist	*token_list_helper(t_dlist *token_list, bool set)
{
	static t_dlist	*list = NULL;

	if (set)
		list = token_list;
	return (list);
}

void	set_token_list(t_dlist *token_list)
{
	token_list_helper(token_list, true);
}

t_dlist	*get_token_list(void)
{
	return (token_list_helper(NULL, false));
}
