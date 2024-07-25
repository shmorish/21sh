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

// must free the return value
char	*get_env_value(t_dlist *head, char *key)
{
	t_dlist	*env;

	if (ft_memcmp(key, "0", 2) == 0)
		return (malloc_wrapper(ft_strdup(CURRENT_SHELL)));
	if (ft_memcmp(key, "?", 2) == 0)
		return (malloc_wrapper(ft_itoa(get_exit_status())));
	env = get_envlist_with_key(head, key);
	if (env)
		return (malloc_wrapper(ft_strdup(((t_env *)env->content)->value)));
	return (NULL);
}

static int	compare_env(void *actual, void *expected)
{
	t_env	*actual_env;
	t_env	*expected_env;
	char	*actual_name;
	char	*expected_name;

	actual_env = actual;
	actual_name = actual_env->name;
	expected_env = expected;
	expected_name = expected_env->name;
	if (!ft_memcmp(actual_name, expected_name,
			ft_strlen(expected_name) + 1))
		return (1);
	return (0);
}

t_dlist	*get_envlist_with_key(t_dlist *head, char *key)
{
	t_env		env;
	t_dlist		*find;

	env.name = key;
	find = ft_dlstfind(head, &env, compare_env);
	return (find);
}
