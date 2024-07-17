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

t_env	*delete_env_value(t_env *head, char *key)
{
	t_env	*current;
	t_env	*prev;
	t_env	*next;

	current = head;
	while (current)
	{
		if (!ft_memcmp(current->name, key, ft_strlen(key) + 1))
		{
			prev = current->prev;
			next = current->next;
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			free(current->name);
			free(current->value);
			free(current);
			break ;
		}
		current = current->next;
	}
	return (head);
}
