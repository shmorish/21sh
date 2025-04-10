/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

void	print_env(void)
{
	t_env	*env;
	t_env	*head;

	head = get_env_head();
	env = head;
	while (env)
	{
		if (!env->hidden)
			if (env->value)
				ft_printf("%s=%s\n", env->name, env->value);
		env = env->next;
		if (env == head)
			break ;
	}
}

static void	init_num_to_zero(void)
{
	t_env	*env;
	t_env	*head;

	head = get_env_head();
	env = head;
	while (env)
	{
		env->num = 0;
		env = env->next;
		if (env == head)
			break ;
	}
}

static void	sort_env(void)
{
	t_env	*head;
	t_env	*sort1;
	t_env	*sort2;

	init_num_to_zero();
	head = get_env_head();
	sort1 = head;
	while (sort1)
	{
		sort2 = head;
		while (sort2)
		{
			if (sort1->name && sort2->name)
			{
				if (ft_strcmp(sort1->name, sort2->name) >= 0)
					sort1->num++;
			}
			sort2 = sort2->next;
			if (sort2 == head)
				break ;
		}
		sort1 = sort1->next;
		if (sort1 == head)
			break ;
	}
}

void	print_env_export(void)
{
	t_env	*env;
	t_env	*printed;
	int		i;

	i = 1;
	sort_env();
	env = get_env_head();
	while (env)
	{
		if (env->num == i)
		{
			if (!env->hidden)
			{
				if (env->value)
					ft_printf("declare -x %s=\"%s\"\n", env->name, env->value);
				else
					ft_printf("declare -x %s\n", env->name);
			}
			printed = env;
			i++;
		}
		env = env->next;
		if (env == printed)
			break ;
	}
}
