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

// char	*get_env_value(t_env *head, char *key)
// {
// 	t_env	*current;

// 	current = head;
// 	if (ft_memcmp(key, "?", 2) == 0)
// 		return (ft_itoa(get_exit_status()));
// 	while (current)
// 	{
// 		if (!ft_memcmp(current->name, key, ft_strlen(key) + 1))
// 			return (current->value);
// 		current = current->next;
// 	}
// 	return (NULL);
// }

char	*get_env_value(t_env *head, char *key)
{
	t_env	*current;

	current = head;
	while (current)
	{
		if (!ft_memcmp(current->name, key, ft_strlen(key) + 1))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

bool	get_env_hidden(t_env *head, char *key)
{
	t_env	*current;

	current = head;
	while (current)
	{
		if (!ft_memcmp(current->name, key, ft_strlen(key) + 1))
			return (current->hidden);
		current = current->next;
	}
	return (false);
}

t_env	*get_env_by_key(t_env *head, char *key)
{
	t_env	*current;

	current = head;
	while (current)
	{
		if (!ft_memcmp(current->name, key, ft_strlen(key) + 1))
			return (current);
		current = current->next;
	}
	return (NULL);
}
