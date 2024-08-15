/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "executor.h"

char	*get_env_value(char *key)
{
	t_env	*env;

	if (key == NULL)
		return (NULL);
	if (ft_memcmp(key, "?", 2) == 0)
		return (ft_itoa(get_exit_status()));
	if (ft_memcmp(key, "$", 2) == 0)
		return (ft_itoa(get_proccess_id()));
	env = get_env_by_key(key);
	if (env)
		return (ft_strdup(env->value));
	return (NULL);
}

t_env	*get_env_by_key(char *key)
{
	t_env	*head;
	t_env	*current;

	head = get_env_head();
	if (head == NULL)
		return (NULL);
	current = head;
	while (1)
	{
		if (ft_memcmp(current->name, key, ft_strlen(key) + 1) == 0)
		{
			return (current);
		}
		current = current->next;
		if (current == head)
			break ;
	}
	return (NULL);
}
