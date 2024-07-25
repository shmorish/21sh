/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	free_env(void *env)
{
	t_env	*tmp;

	tmp = (t_env *)env;
	free(tmp->name);
	free(tmp->value);
	free(tmp);
}

void	delete_env_value(t_dlist **head, char *key)
{
	t_dlist	*list;

	list = ft_dlstpop_middle(get_envlist_with_key(*head, key));
	ft_dlstdelone((t_dlist *)list, free_env);
}

void	free_all_env(t_dlist *head)
{
	ft_dlstclear(&head, free_env);
}
