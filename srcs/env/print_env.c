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

void	print_env(t_env *head)
{
	t_env	*current;

	current = head;
	while (current)
	{
		if (!current->hidden)
		{
			printf("%s=%s\n", current->name, current->value);
		}
		current = current->next;
	}
}

static void	sort_env(t_env *head)
{
	t_env	*current_1;
	t_env	*current_2;
	int		i;

	current_1 = head;
	while (current_1)
	{
		current_2 = head;
		i = 0;
		while (current_2)
		{
			if (ft_memcmp(current_1->name, current_2->name,
					ft_strlen(current_1->name) + 1) > 0)
			{
				i++;
			}
			current_2 = current_2->next;
		}
		current_1->num = i;
		current_1 = current_1->next;
	}
}

static t_env	*find_env_by_num(t_env *head, int num)
{
	t_env	*current;

	current = head;
	while (current)
	{
		if (current->num == num)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

void	print_env_export(t_env *head)
{
	t_env	*current;
	int		num;

	sort_env(head);
	num = 0;
	while (find_env_by_num(head, num))
	{
		current = find_env_by_num(head, num);
		if (!current->hidden)
		{
			printf("declare -x %s=\"%s\"\n", current->name, current->value);
		}
		num++;
	}
}
