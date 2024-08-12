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

static void	free_env(t_env *env)
{
	free(env->name);
	env->name = NULL;
	free(env->value);
	env->value = NULL;
	free(env);
	env = NULL;
}

void	pop_env(t_env *env)
{
	env->prev->next = env->next;
	env->next->prev = env->prev;
	free_env(env);
}

// unset key
void	delete_env_value(char *key)
{
	t_env	*env;
	t_env	*head;

	env = get_env_by_key(key);
	head = get_env_head();
	if (env)
	{
		if (env == head)
		{
			if (env->next == env)
			{
				store_env_head(NULL);
				return ;
			}
			pop_env(env);
			store_env_head(env->next);
		}
		else
			pop_env(env);
	}
}
