/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env *get_env_head(void);

char	*split_env_to_key(char *envp)
{
	int		i;
	char	*key;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	key = ft_substr(envp, 0, i);
	key = malloc_wrapper(key);
	return (key);
}

char	*split_env_to_value(char *envp)
{
	int		i;
	char	*value;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	if (envp[i] == '=')
		i++;
	value = ft_strdup(envp + i);
	value = malloc_wrapper(value);
	return (value);
}


void	free_all_env(void)
{
	t_env	*head;
	t_env	*current;
	t_env	*tmp;

	head = get_env_head();
	current = head->next;
	while (current != head)
	{
		tmp = current;
		current = current->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
	free(head);
}
