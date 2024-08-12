/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_env_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static t_env	*env_head_helper(t_env *head, bool set)
{
	static t_env	*env_head = NULL;

	if (set)
		env_head = head;
	return (env_head);
}

void	store_env_head(t_env *head)
{
	env_head_helper(head, true);
}

t_env	*get_env_head(void)
{
	return (env_head_helper(NULL, false));
}
