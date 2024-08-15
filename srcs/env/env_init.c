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

void	node_add_back(t_env *new)
{
	t_env	*head;

	head = get_env_head();
	if (new == NULL)
		return ;
	if (head == NULL)
	{
		new->next = new;
		new->prev = new;
		store_env_head(new);
		return ;
	}
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}

t_env	*node_init(bool hidden)
{
	t_env	*new;

	new = malloc_wrapper(ft_calloc(1, sizeof(t_env)));
	new->name = NULL;
	new->value = NULL;
	new->hidden = hidden;
	new->num = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	env_init(char **envp)
{
	char	*key;
	char	*value;
	int		i;

	add_init_shell_variable();
	if (envp == NULL)
		return ;
	i = 0;
	while (envp[i])
	{
		key = split_env_to_key(envp[i]);
		value = split_env_to_value(envp[i]);
		add_env_value(key, value, false);
		free(key);
		free(value);
		i++;
	}
}

// shell変数 (PS1, PS2, PATH) を追加
// 環境変数 (PWD, SHLVL, OLDPWD) を追加

// [export KEY=VALUE] で環境変数を追加
// [export KEY]       でSHELL変数を環境変数へ昇格
// [export KEY]       で環境変数に代入
// [export]           で全環境変数を表示
// [unset KEY]        で環境変数を削除

// KEY=
// env -> nothing
// export KEY
// env -> KEY=