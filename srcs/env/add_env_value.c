/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*create_env(char *name, char *value, bool hidden)
{
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
	{
		perror("malloc");
		exit(1);
	}
	new_env->name = name;
	new_env->value = value;
	new_env->hidden = hidden;
	new_env->next = NULL;
	new_env->prev = NULL;
	new_env->num = 0;
	return (new_env);
}

t_env	*add_env_value(t_env *head, t_env *new_env)
{
	t_env	*current;
	char	*key;
	bool	hidden;

	if (!new_env)
		return (head);
	if (!head)
		return (new_env);
	hidden = false;
	key = new_env->name;
	if (get_env_by_key(head, key))
	{
		head = delete_env_value(head, key);
	}
	current = head;
	while (current->next)
		current = current->next;
	current->next = new_env;
	new_env->hidden = hidden;
	new_env->prev = current;
	return (head);
}
