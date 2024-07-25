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

	new_env = (t_env *)ft_calloc(1, sizeof(t_env));
	new_env = malloc_wrapper(new_env);
	new_env->name = name;
	new_env->value = value;
	new_env->hidden = hidden;
	new_env->num = 0;
	return (new_env);
}

void	add_env_value(t_dlist **head, char *name, char *value, bool hidden)
{
	t_env	*new_env;
	char	*val;

	val = get_env_value(*head, name);
	if (val)
		delete_env_value(head, name);
	new_env = create_env(name, value, hidden);
	ft_dlstadd_back(head, ft_dlstnew(new_env));
}
