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

// void	print_env(t_dlist *head)
// {
// 	t_dlist	*current;
// 	char	*key;
// 	char	*value;

// 	current = head;
// 	while (current)
// 	{
// 		if (!((t_env *)current->content)->hidden)
// 		{
// 			key = ((t_env *)current->content)->name;
// 			value = ((t_env *)current->content)->value;
// 			printf("%s=%s\n", key, value);
// 		}
// 		current = current->next;
// 	}
// }

// void	init_num_to_zero(t_dlist *head)
// {
// 	t_dlist	*current;

// 	current = head;
// 	while (current)
// 	{
// 		((t_env *)current->content)->num = 0;
// 		current = current->next;
// 	}
// }

// static void	sort_env(t_dlist *head)
// {
// 	t_dlist	*current_1;
// 	t_dlist	*current_2;
// 	int		i;
// 	char	*one;
// 	char	*two;

// 	init_num_to_zero(head);
// 	current_1 = head;
// 	while (current_1)
// 	{
// 		current_2 = head;
// 		i = 0;
// 		while (current_2)
// 		{
// 			one = ((t_env *)current_1->content)->name;
// 			two = ((t_env *)current_2->content)->name;
// 			if (ft_strcmp(one, two) > 0)
// 				i++;
// 			current_2 = current_2->next;
// 		}
// 		((t_env *)current_1->content)->num = i;
// 		current_1 = current_1->next;
// 	}
// }

// static t_dlist	*find_env_by_num(t_dlist *head, int num)
// {
// 	t_dlist	*current;
// 	int		current_num;

// 	current = head;
// 	while (current)
// 	{
// 		current_num = ((t_env *)current->content)->num;
// 		if (current_num == num)
// 		{
// 			return (current);
// 		}
// 		current = current->next;
// 	}
// 	return (NULL);
// }

// void	print_env_export(t_dlist *head)
// {
// 	t_dlist	*current;
// 	int		num;
// 	bool	hidden;
// 	char	*name;
// 	char	*value;

// 	sort_env(head);
// 	num = 0;
// 	while (find_env_by_num(head, num))
// 	{
// 		current = find_env_by_num(head, num);
// 		hidden = ((t_env *)current->content)->hidden;
// 		name = ((t_env *)current->content)->name;
// 		value = ((t_env *)current->content)->value;
// 		if (!hidden)
// 		{
// 			printf("%s=%s\n", name, value);
// 		}
// 		num++;
// 	}
// }
