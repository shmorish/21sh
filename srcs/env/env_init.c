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
	key = malloc_wrapper(key);
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
	value = malloc_wrapper(value);
	return (value);
}

static t_dlist	*add_shell_env(void)
{
	t_dlist	*head;
	char	*key;
	char	*val;

	key = malloc_wrapper(ft_strdup("PS1"));
	val = malloc_wrapper(ft_strdup("minishell$ "));
	head = ft_dlstnew(create_env(key, val, true));
	key = malloc_wrapper(ft_strdup("PS2"));
	val = malloc_wrapper(ft_strdup("> "));
	ft_dlstadd_back(&head, ft_dlstnew(create_env(key, val, true)));
	key = malloc_wrapper(ft_strdup("SHLVL"));
	val = malloc_wrapper(ft_strdup("0"));
	ft_dlstadd_back(&head, ft_dlstnew(create_env(key, val, true)));
	key = malloc_wrapper(ft_strdup("PATH"));
	val = malloc_wrapper(ft_strdup("/usr/local/bin:/bin:/usr/bin:."));
	ft_dlstadd_back(&head, ft_dlstnew(create_env(key, val, true)));
	return (head);
}

t_dlist	*env_init(char **envp)
{
	t_dlist	*head;
	t_env	*env;
	char	*key;
	char	*val;
	int		i;

	head = add_shell_env();
	if (envp != NULL)
	{
		i = 0;
		while (envp[i])
		{
			key = split_env_to_key(envp[i]);
			val = split_env_to_value(envp[i]);
			env = create_env(key, val, false);
			ft_dlstadd_back(&head, ft_dlstnew(env));
			i++;
		}
	}
	return (head);
}
