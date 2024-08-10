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
t_env *get_env_head(void);
void store_env_head(t_env *head);
t_env	*node_init(bool hidden);
void	node_add_back(t_env *new);

void	add_env_value(char *key, char *value, bool hidden)
{
	t_env	*new;

	new = node_init(hidden);
	new->name = malloc_wrapper(ft_strdup(key));
	// printf("key: %s\n", key);
	// printf("new->name: %s\n", new->name);
	if (value)
		new->value = malloc_wrapper(ft_strdup(value));
	else
		new->value = NULL;
	// printf("value: [%s]\n", value);
	node_add_back(new);
}


void	add_init_shell_variable(void)
{
	add_env_value("PS1", "minishell$ ", true);
	add_env_value("PS2", "> ", true);
	add_env_value("PATH", "/usr/local/bin:/bin:/usr/bin:.", true);
	add_env_value("SHLVL", "0", false);
	add_env_value("OLDPWD", NULL, false);
	add_env_value("PWD", getcwd(NULL, 0), false);
}
