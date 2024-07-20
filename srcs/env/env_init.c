/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	*split_env_to_key(char *envp)
{
	int		i;
	char	*key;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	key = ft_substr(envp, 0, i);
	if (!key)
	{
		perror("malloc");
		exit(1);
	}
	return (key);
}

static char	*split_env_to_value(char *envp)
{
	int		i;
	char	*value;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	if (envp[i] == '=')
		i++;
	value = ft_strdup(envp + i);
	if (!value)
	{
		perror("malloc");
		exit(1);
	}
	return (value);
}

static t_env	*add_prompt_env(t_env *head)
{
	t_env	*new_env;
	char	*key;
	char	*value;

	key = ft_strdup("PS1");
	value = ft_strdup("minishell$ ");
	new_env = create_env(key, value, true);
	head = add_env_value(head, new_env);
	key = ft_strdup("PS2");
	value = ft_strdup("> ");
	new_env = create_env(key, value, true);
	head = add_env_value(head, new_env);
	return (head);
}

t_env	*env_init(char **envp)
{
	t_env	*head;
	t_env	*new_env;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	head = NULL;
	if (envp != NULL)
	{
		while (envp[i])
		{
			key = split_env_to_key(envp[i]);
			value = split_env_to_value(envp[i]);
			new_env = create_env(key, value, false);
			head = add_env_value(head, new_env);
			i++;
		}
	}
	head = add_prompt_env(head);
	return (head);
}

void	free_all_env(t_env *head)
{
	t_env	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
}
