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
#include "libft.h"

// export key=value
// export key
void	add_env_value(char *key, char *value, bool hidden)
{
	t_env	*new;

	new = get_env_by_key(key);
	if (new)
	{
		if (value)
		{
			free(new->value);
			new->value = check_malloc_error(ft_strdup(value));
		}
		new->hidden = hidden;
		return ;
	}
	new = node_init(hidden);
	new->name = check_malloc_error(ft_strdup(key));
	if (value)
		new->value = check_malloc_error(ft_strdup(value));
	else
		new->value = NULL;
	node_add_back(new);
}

void	add_init_shell_variable(void)
{
	char	*current;	

	add_env_value("PATH", DEFAULT_PATH, true);
	add_env_value("PS1", "minishell$ ", true);
	add_env_value("PS2", "> ", true);
	add_env_value("OLDPWD", NULL, false);
	current = getcwd(NULL, 0);
	add_env_value("PWD", current, false);
	free(current);
	add_env_value("SHLVL", "0", false);
}
